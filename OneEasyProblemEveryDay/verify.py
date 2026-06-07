import sys; sys.stdout.reconfigure(encoding="utf-8")

"""
OEPED verifier — validates daily entries and updates streak.json.

Local usage:
  python verify.py                  # check today
  python verify.py 2026-06-06       # check a specific date

GHA usage (reads CHANGED_PATHS env var, writes GITHUB_OUTPUT):
  CHANGED_PATHS="..." python verify.py --gha
"""

import argparse
import datetime as dt
import json
import os
import re
from pathlib import Path

ROOT = Path(__file__).parent
STREAK_FILE = ROOT / "streak.json"
DATE_RE = re.compile(r"^OneEasyProblemEveryDay/(\d{4}-\d{2}-\d{2})/")

SKIP = {"OneEasyProblemEveryDay/README.md", "OneEasyProblemEveryDay/streak.json"}


def load_streak() -> dict:
    if STREAK_FILE.exists():
        return json.loads(STREAK_FILE.read_text(encoding="utf-8"))
    return {"streak": 0, "last_date": ""}


def save_streak(state: dict) -> None:
    STREAK_FILE.write_text(json.dumps(state, indent=2) + "\n", encoding="utf-8")


def last_date_from_state(state: dict) -> dt.date | None:
    try:
        return dt.date.fromisoformat(state["last_date"]) if state.get("last_date") else None
    except ValueError:
        return None


def update_streak(state: dict, date: dt.date) -> dict:
    streak = int(state.get("streak", 0))
    last_date = last_date_from_state(state)

    if last_date == date:
        pass  # already counted today
    elif last_date is not None and date == last_date + dt.timedelta(days=1):
        streak += 1
    else:
        streak = 1

    return {"streak": streak, "last_date": date.isoformat()}


def parse_changed_paths(raw: str) -> tuple[list[dt.date], list[str]]:
    valid_dates, invalid = [], []
    for line in raw.splitlines():
        path = line.strip().replace("\\", "/")
        if not path or path in SKIP:
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


def run_gha() -> None:
    raw = os.environ.get("CHANGED_PATHS", "").strip()
    valid_dates, invalid = parse_changed_paths(raw)

    if invalid:
        print("ERROR: Invalid OEPED paths — use OneEasyProblemEveryDay/YYYY-MM-DD/<file>")
        for p in invalid:
            print(f"  {p}")
        sys.exit(1)

    state = load_streak()
    has_update = False

    if valid_dates:
        last_date = last_date_from_state(state)

        # Ignore changes to past date folders (redos) — they must not affect the streak
        if last_date is not None:
            skipped = [d for d in valid_dates if d < last_date]
            for d in skipped:
                print(f"SKIP: {d} is older than last recorded date {last_date} (redo ignored)")
            valid_dates = [d for d in valid_dates if d >= last_date]

        if valid_dates:
            newest = max(valid_dates)
            state = update_streak(state, newest)
            save_streak(state)
            has_update = True

    github_output = os.environ.get("GITHUB_OUTPUT")
    if github_output:
        with open(github_output, "a", encoding="utf-8") as fh:
            fh.write(f"streak={state['streak']}\n")
            fh.write(f"last_date={state['last_date']}\n")
            fh.write(f"has_daily_update={'true' if has_update else 'false'}\n")

    print(f"streak={state['streak']}  last_date={state['last_date']}")


def run_local(target_date: dt.date) -> None:
    date_dir = ROOT / target_date.isoformat()
    if not date_dir.exists():
        print(f"MISSING: no entry for {target_date}  ({date_dir})")
        sys.exit(1)

    files = [f for f in date_dir.iterdir() if f.is_file()]
    if not files:
        print(f"EMPTY: {date_dir} exists but has no files")
        sys.exit(1)

    print(f"OK: {target_date} — {len(files)} file(s)")
    for f in files:
        print(f"  {f.name}")

    state = load_streak()
    new_state = update_streak(state, target_date)
    save_streak(new_state)
    print(f"streak={new_state['streak']}  last_date={new_state['last_date']}")


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("date", nargs="?", help="YYYY-MM-DD (default: today)")
    parser.add_argument("--gha", action="store_true", help="run in GHA mode")
    parser.add_argument("--streak-file", type=Path, help="override streak.json path")
    args = parser.parse_args()

    if args.streak_file:
        global STREAK_FILE
        STREAK_FILE = args.streak_file

    if args.gha:
        run_gha()
    else:
        if args.date:
            try:
                target = dt.date.fromisoformat(args.date)
            except ValueError:
                print(f"Invalid date: {args.date}")
                sys.exit(1)
        else:
            target = dt.date.today()
        run_local(target)


if __name__ == "__main__":
    main()
