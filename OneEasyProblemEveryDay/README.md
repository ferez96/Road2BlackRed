# One Easy Problem Every Day

[![OEPED Streak](https://img.shields.io/badge/dynamic/json?style=for-the-badge&url=https://raw.githubusercontent.com/ferez96/Road2BlackRed/master/OneEasyProblemEveryDay/streak.json&query=%24.streak&label=%F0%9F%8F%86%20Streak&color=gold&suffix=%20days)](streak.json)

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

## Naming

Follow the same convention as `problem-solving/` — see `.cursorrules` at the repo root.
