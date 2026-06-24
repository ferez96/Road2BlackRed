import sys; sys.stdout.reconfigure(encoding="utf-8")

"""oeped.py — one-for-all OEPED helper.

Usage:
  python oeped.py mkdir                    create today's date directory
  python oeped.py run                      go run today's .go file
  python oeped.py streak                   show current streak
  python oeped.py record [YYYY-MM-DD]      record a solve and update streak (default: today)
  python oeped.py gha                      run in GHA mode (reads CHANGED_PATHS)
  python oeped.py simulate <path>          simulate a GHA push with the given path
"""

import argparse
import datetime as dt
import json
import os
import re
import subprocess
from pathlib import Path

ROOT = Path(__file__).parent
STREAK_FILE = ROOT / "streak.json"
DATE_RE = re.compile(r"^OneEasyProblemEveryDay/(\d{4}-\d{2}-\d{2})/")
FLAT_FILE_RE = re.compile(r"^OneEasyProblemEveryDay/[^/]+$")


# ---------------------------------------------------------------------------
# Streak helpers
# ---------------------------------------------------------------------------

def load_streak(streak_file: Path | None = None) -> dict:
    f = streak_file or STREAK_FILE
    if f.exists():
        return json.loads(f.read_text(encoding="utf-8"))
    return {"streak": 0, "last_date": ""}


def save_streak(state: dict, streak_file: Path | None = None) -> None:
    f = streak_file or STREAK_FILE
    f.write_text(json.dumps(state, indent=2) + "\n", encoding="utf-8")


def last_date_from_state(state: dict) -> dt.date | None:
    try:
        return dt.date.fromisoformat(state["last_date"]) if state.get("last_date") else None
    except ValueError:
        return None


def update_streak(state: dict, date: dt.date) -> dict:
    streak = int(state.get("streak", 0))
    last_date = last_date_from_state(state)

    if last_date != date:
        if last_date is not None and date == last_date + dt.timedelta(days=1):
            streak += 1
        else:
            streak = 1

    return {"streak": streak, "last_date": date.isoformat()}


def parse_changed_paths(raw: str) -> tuple[list[dt.date], list[str]]:
    valid_dates, invalid = [], []
    for line in raw.splitlines():
        path = line.strip().replace("\\", "/")
        if not path or FLAT_FILE_RE.match(path):
            continue
        m = DATE_RE.match(path)
        if not m:
            invalid.append(path)
            continue
        try:
            valid_dates.append(dt.date.fromisoformat(m.group(1)))
        except ValueError:
            invalid.append(path)
    return valid_dates, invalid


# ---------------------------------------------------------------------------
# Subcommands
# ---------------------------------------------------------------------------

def cmd_mkdir(args: argparse.Namespace) -> None:
    d = ROOT / dt.date.today().isoformat()
    d.mkdir()
    print(d)


def cmd_run(args: argparse.Namespace) -> None:
    d = ROOT / dt.date.today().isoformat()
    files = list(d.glob("*.go"))
    if not files:
        print(f"no .go file found in {d}", file=sys.stderr)
        sys.exit(1)
    subprocess.run(["go", "run", *files], check=True)


def cmd_streak(args: argparse.Namespace) -> None:
    data = load_streak()
    print(json.dumps(data, indent=2))


def cmd_record(args: argparse.Namespace) -> None:
    if args.date:
        try:
            target = dt.date.fromisoformat(args.date)
        except ValueError:
            print(f"Invalid date: {args.date}")
            sys.exit(1)
    else:
        target = dt.date.today()

    date_dir = ROOT / target.isoformat()
    if not date_dir.exists():
        print(f"MISSING: no entry for {target}  ({date_dir})")
        sys.exit(1)

    files = [f for f in date_dir.iterdir() if f.is_file()]
    if not files:
        print(f"EMPTY: {date_dir} exists but has no files")
        sys.exit(1)

    print(f"OK: {target} — {len(files)} file(s)")
    for f in files:
        print(f"  {f.name}")

    state = load_streak()
    new_state = update_streak(state, target)
    save_streak(new_state)
    print(f"streak={new_state['streak']}  last_date={new_state['last_date']}")


def cmd_gha(args: argparse.Namespace) -> None:
    streak_file: Path | None = args.streak_file
    raw = os.environ.get("CHANGED_PATHS", "").strip()
    valid_dates, invalid = parse_changed_paths(raw)

    if invalid:
        print("ERROR: Invalid OEPED paths — use OneEasyProblemEveryDay/YYYY-MM-DD/<file>")
        for p in invalid:
            print(f"  {p}")
        sys.exit(1)

    state = load_streak(streak_file)

    if valid_dates:
        last_date = last_date_from_state(state)

        if last_date is not None:
            for d in valid_dates:
                if d < last_date:
                    print(f"SKIP: {d} is older than last recorded date {last_date} (redo ignored)")
            valid_dates = [d for d in valid_dates if d >= last_date]

        if valid_dates:
            state = update_streak(state, max(valid_dates))
            save_streak(state, streak_file)

    github_output = os.environ.get("GITHUB_OUTPUT")
    if github_output:
        with open(github_output, "a", encoding="utf-8") as fh:
            fh.write(f"streak={state['streak']}\n")
            fh.write(f"last_date={state['last_date']}\n")
            fh.write(f"has_daily_update={'true' if valid_dates else 'false'}\n")

    print(f"streak={state['streak']}  last_date={state['last_date']}")


def cmd_simulate(args: argparse.Namespace) -> None:
    os.environ["CHANGED_PATHS"] = args.path
    cmd_gha(argparse.Namespace(streak_file=None))


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def main() -> None:
    parser = argparse.ArgumentParser(prog="oeped.py")
    sub = parser.add_subparsers(dest="cmd", required=True)

    sub.add_parser("mkdir")
    sub.add_parser("run")
    sub.add_parser("streak")

    p_record = sub.add_parser("record")
    p_record.add_argument("date", nargs="?", help="YYYY-MM-DD (default: today)")

    p_gha = sub.add_parser("gha")
    p_gha.add_argument("--streak-file", type=Path, help=argparse.SUPPRESS)

    p_sim = sub.add_parser("simulate")
    p_sim.add_argument("path", help="changed file path")

    args = parser.parse_args()

    DISPATCH = {
        "mkdir": cmd_mkdir,
        "run": cmd_run,
        "streak": cmd_streak,
        "record": cmd_record,
        "gha": cmd_gha,
        "simulate": cmd_simulate,
    }
    DISPATCH[args.cmd](args)


if __name__ == "__main__":
    main()
