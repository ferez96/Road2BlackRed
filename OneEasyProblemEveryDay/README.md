# One Easy Problem Every Day (OEPE)

## Goal

Solve at least one easy problem per day and keep a consistent streak.

## Folder Rules

- Put each day's work under `OneEasyProblemEveryDay/YYYY-MM-DD/`.
- Add one or more solution files in that date folder.
- Keep `README.md` and `streak.json` at the root of `OneEasyProblemEveryDay/`.

Example:

```text
OneEasyProblemEveryDay/
  2026-04-22/
    leetcode-1-two-sum.cpp
  README.md
  streak.json
```

## Naming Suggestion

Use a descriptive filename:

`<platform>-<problem-id>-<short-title>.<ext>`

Examples:

- `leetcode-14-longest-common-prefix.cpp`
- `codeforces-71a-way-too-long-words.py`

## Streak Policy

- The workflow updates `streak.json` when OEPE files are pushed.
- A valid daily update is a changed file under `OneEasyProblemEveryDay/YYYY-MM-DD/`.
- If the new date is exactly 1 day after the previous `last_date`, streak increases by 1.
- Otherwise, streak resets to 1 for the new date.
