import sys; sys.stdout.reconfigure(encoding="utf-8")

import datetime as dt
import json
import os
import subprocess
import tempfile
from pathlib import Path

import pytest

# ---------------------------------------------------------------------------
# Helpers
# ---------------------------------------------------------------------------

VERIFY = Path(__file__).parent / "verify.py"


def run_gha(changed_paths: str, streak_state: dict | None = None) -> subprocess.CompletedProcess:
    """Run verify.py --gha with an isolated streak.json in a temp dir."""
    with tempfile.TemporaryDirectory() as tmp:
        tmp_path = Path(tmp)
        streak_file = tmp_path / "streak.json"
        if streak_state is not None:
            streak_file.write_text(json.dumps(streak_state, indent=2) + "\n", encoding="utf-8")

        env = {**os.environ, "CHANGED_PATHS": changed_paths}
        result = subprocess.run(
            [sys.executable, str(VERIFY), "--gha", "--streak-file", str(streak_file)],
            env=env,
            capture_output=True,
            text=True,
        )

        # Read back the streak written by the script (if any)
        if streak_file.exists():
            written = json.loads(streak_file.read_text(encoding="utf-8"))
        else:
            written = None

        result.streak_state = written
        return result


def make_path(date: str, filename: str = "solution.go") -> str:
    return f"OneEasyProblemEveryDay/{date}/{filename}"


# ---------------------------------------------------------------------------
# update_streak unit tests (pure function, no filesystem)
# ---------------------------------------------------------------------------

from verify import update_streak, parse_changed_paths  # noqa: E402


class TestUpdateStreak:
    def test_first_ever_solve(self):
        state = update_streak({"streak": 0, "last_date": ""}, dt.date(2026, 6, 1))
        assert state == {"streak": 1, "last_date": "2026-06-01"}

    def test_consecutive_day_increments(self):
        state = update_streak({"streak": 3, "last_date": "2026-06-01"}, dt.date(2026, 6, 2))
        assert state == {"streak": 4, "last_date": "2026-06-02"}

    def test_same_day_is_idempotent(self):
        state = update_streak({"streak": 5, "last_date": "2026-06-01"}, dt.date(2026, 6, 1))
        assert state == {"streak": 5, "last_date": "2026-06-01"}

    def test_gap_resets_streak(self):
        state = update_streak({"streak": 10, "last_date": "2026-06-01"}, dt.date(2026, 6, 3))
        assert state == {"streak": 1, "last_date": "2026-06-03"}

    def test_invalid_last_date_treated_as_fresh(self):
        state = update_streak({"streak": 5, "last_date": "not-a-date"}, dt.date(2026, 6, 1))
        assert state == {"streak": 1, "last_date": "2026-06-01"}


# ---------------------------------------------------------------------------
# parse_changed_paths unit tests
# ---------------------------------------------------------------------------


class TestParseChangedPaths:
    def test_valid_path(self):
        dates, invalid = parse_changed_paths(make_path("2026-06-01"))
        assert dates == [dt.date(2026, 6, 1)]
        assert invalid == []

    def test_skip_readme(self):
        dates, invalid = parse_changed_paths("OneEasyProblemEveryDay/README.md")
        assert dates == []
        assert invalid == []

    def test_skip_streak_json(self):
        dates, invalid = parse_changed_paths("OneEasyProblemEveryDay/streak.json")
        assert dates == []
        assert invalid == []

    def test_invalid_path_outside_date_folder(self):
        _, invalid = parse_changed_paths("OneEasyProblemEveryDay/solution.go")
        assert invalid == ["OneEasyProblemEveryDay/solution.go"]

    def test_multiple_files_same_date(self):
        raw = "\n".join([make_path("2026-06-01", "a.go"), make_path("2026-06-01", "b.go")])
        dates, invalid = parse_changed_paths(raw)
        assert dates == [dt.date(2026, 6, 1), dt.date(2026, 6, 1)]
        assert invalid == []

    def test_windows_backslash_paths(self):
        path = "OneEasyProblemEveryDay\\2026-06-01\\solution.go"
        dates, invalid = parse_changed_paths(path)
        assert dates == [dt.date(2026, 6, 1)]
        assert invalid == []


# ---------------------------------------------------------------------------
# GHA integration tests (subprocess, real streak.json read/write)
# ---------------------------------------------------------------------------


class TestGhaStreakProgression:
    def test_fresh_start(self):
        result = run_gha(make_path("2026-06-01"))
        assert result.returncode == 0
        assert result.streak_state == {"streak": 1, "last_date": "2026-06-01"}

    def test_consecutive_days_build_streak(self):
        result = run_gha(
            make_path("2026-06-02"),
            streak_state={"streak": 1, "last_date": "2026-06-01"},
        )
        assert result.returncode == 0
        assert result.streak_state == {"streak": 2, "last_date": "2026-06-02"}

    def test_same_day_second_solve_is_idempotent(self):
        result = run_gha(
            make_path("2026-06-01"),
            streak_state={"streak": 3, "last_date": "2026-06-01"},
        )
        assert result.returncode == 0
        assert result.streak_state == {"streak": 3, "last_date": "2026-06-01"}

    def test_gap_resets_streak(self):
        result = run_gha(
            make_path("2026-06-05"),
            streak_state={"streak": 4, "last_date": "2026-06-01"},
        )
        assert result.returncode == 0
        assert result.streak_state == {"streak": 1, "last_date": "2026-06-05"}

    def test_no_changed_paths_leaves_streak_unchanged(self):
        state = {"streak": 7, "last_date": "2026-06-01"}
        result = run_gha("", streak_state=state)
        assert result.returncode == 0
        assert result.streak_state == state

    def test_only_skipped_files_leaves_streak_unchanged(self):
        state = {"streak": 7, "last_date": "2026-06-01"}
        paths = "OneEasyProblemEveryDay/README.md\nOneEasyProblemEveryDay/streak.json"
        result = run_gha(paths, streak_state=state)
        assert result.returncode == 0
        assert result.streak_state == state

    def test_invalid_path_exits_nonzero(self):
        result = run_gha("some/random/file.go")
        assert result.returncode != 0
        assert "ERROR" in result.stdout

    def test_multiple_valid_dates_uses_newest(self):
        # Two date folders changed in one push — newest drives the streak update
        paths = "\n".join([make_path("2026-06-02"), make_path("2026-06-03")])
        result = run_gha(paths, streak_state={"streak": 1, "last_date": "2026-06-02"})
        assert result.returncode == 0
        assert result.streak_state == {"streak": 2, "last_date": "2026-06-03"}


# ---------------------------------------------------------------------------
# Redo protection tests (the fixed bug)
# ---------------------------------------------------------------------------


class TestRedoProtection:
    def test_redo_old_problem_does_not_reset_streak(self):
        state = {"streak": 10, "last_date": "2026-06-07"}
        result = run_gha(make_path("2026-04-22"), streak_state=state)
        assert result.returncode == 0
        # streak must be untouched
        assert result.streak_state == state

    def test_redo_prints_skip_message(self):
        state = {"streak": 5, "last_date": "2026-06-07"}
        result = run_gha(make_path("2026-04-22"), streak_state=state)
        assert "SKIP" in result.stdout
        assert "2026-04-22" in result.stdout

    def test_redo_mixed_with_new_day_only_counts_new(self):
        # Redo of old + today's new solve in same push
        paths = "\n".join([make_path("2026-04-22"), make_path("2026-06-08")])
        state = {"streak": 5, "last_date": "2026-06-07"}
        result = run_gha(paths, streak_state=state)
        assert result.returncode == 0
        assert result.streak_state == {"streak": 6, "last_date": "2026-06-08"}

    def test_redo_only_no_streak_json_yet_counts_normally(self):
        # No prior streak — redo of an old problem on first-ever push should count
        result = run_gha(make_path("2026-04-22"), streak_state=None)
        assert result.returncode == 0
        assert result.streak_state == {"streak": 1, "last_date": "2026-04-22"}

    def test_redo_same_as_last_date_is_idempotent(self):
        # Redo of the exact last_date folder (e.g., adding a second solution same day)
        state = {"streak": 3, "last_date": "2026-06-07"}
        result = run_gha(make_path("2026-06-07", "alt-solution.go"), streak_state=state)
        assert result.returncode == 0
        assert result.streak_state == {"streak": 3, "last_date": "2026-06-07"}
