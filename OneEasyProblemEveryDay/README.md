# One Easy Problem Every Day

[![OEPED Streak](https://img.shields.io/badge/dynamic/json?url=https://raw.githubusercontent.com/ferez96/Road2BlackRed/master/OneEasyProblemEveryDay/streak.json&query=%24.streak&label=%F0%9F%8F%86%20streak&color=gold&suffix=%20days)](streak.json)

Daily practice track. One CP problem per day, any platform.

## File Layout

```
OneEasyProblemEveryDay/
  YYYY-MM-DD/
    {platform}-{number}-{slug}.go   (or .py, .cpp, etc.)
```

Example: `2026-04-22/LC-15-3sum.go`

## Streak

`streak.json` tracks the current streak and last active date. Updated automatically by the GitHub Actions workflow on each push that adds a dated entry.

## Local commands

```
just oeped mkdir           # create today's directory (YYYY-MM-DD/)
just oeped run             # go run today's solution
just oeped record          # record today's solve and update streak
just oeped record 2026-06-07  # record a specific date
just oeped streak          # show current streak
```

`oeped.py` is the one-for-all helper script — add new subcommands there as needed.

## Naming

Follow the same convention as `problem-solving/` — see `AGENTS.md` at the repo root.
