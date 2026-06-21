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
just test                  # run tests
just verify                # verify today's entry and update streak.json
just check 2026-06-07      # verify a specific date
just streak                # print current streak
just simulate "OneEasyProblemEveryDay/2026-06-07/solution.go"  # simulate a GHA push
```

## Naming

Follow the same convention as `problem-solving/` — see `AGENTS.md` at the repo root.
