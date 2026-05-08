# Road2BlackRed

Personal competitive-programming archive across multiple years and platforms: Codeforces, CodeChef, Google Code Jam, LeetCode, and more.

[![Repo Size](https://img.shields.io/github/repo-size/ferez96/Road2BlackRed)](https://github.com/ferez96/Road2BlackRed)
[![Last Commit](https://img.shields.io/github/last-commit/ferez96/Road2BlackRed)](https://github.com/ferez96/Road2BlackRed/commits/master)
[![Top Language](https://img.shields.io/github/languages/top/ferez96/Road2BlackRed)](https://github.com/ferez96/Road2BlackRed)
[![OEPE Streak Workflow](https://img.shields.io/github/actions/workflow/status/ferez96/Road2BlackRed/OneEasyProblemEveryDay-update-streak.yaml?label=OEPE%20streak)](https://github.com/ferez96/Road2BlackRed/actions/workflows/OneEasyProblemEveryDay-update-streak.yaml)

## What This Repo Contains

- Problem solving training campaign (ON-GOING).
- Daily-practice track in `OneEasyProblemEveryDay/` (ON-GOING).
- Standalone solutions organized by year and contest/source.
- Historical training notes from early practice sessions.

## Repository Map

- `Archived/` - archived solutions by year.
- `OneEasyProblemEveryDay/` - daily challenge workspace and streak state.
- `.github/workflows/` - automation (including OEPE streak update workflow).

## Run One Solution

Most files are independent programs. Pick a source file and compile/run directly.

### C++ (Linux/macOS, Git Bash, WSL)

```bash
g++ -std=c++17 -O2 -Wall "<path-to-solution>.cpp" -o solution
./solution < input.txt
```

### C++ (Windows PowerShell + g++)

```powershell
g++ -std=c++17 -O2 -Wall "<path-to-solution>.cpp" -o solution.exe
Get-Content "input.txt" | .\solution.exe
```

If a solution uses `freopen(...)`, comment/remove those lines for normal stdin/stdout execution.

## OEPED (One Easy Problem Every Day)

Daily entries should follow:

- `OneEasyProblemEveryDay/YYYY-MM-DD/<solution-file>`
- Example: `OneEasyProblemEveryDay/2026-04-22/leetcode-15-3sum.go`

The OEPED workflow validates this layout and updates `OneEasyProblemEveryDay/streak.json`.

## Early Training Log (2017)

<details>
<summary>Click to expand</summary>

### 09/11/2017
- Practice: [Educational Codeforces Round 32](http://codeforces.com/contest/888)
- Result: 4/7, then 5/7 after more attempts

### 10/11/2017
- Reviewed Educational Codeforces Round 32
- Read [Geometry Concepts](https://www.topcoder.com/community/data-science/data-science-tutorials/geometry-concepts-basic-concepts/) (basic concepts)

### 11/11/2017
- Practice: [Codeforces Round #440 (Div. 2)](http://codeforces.com/contest/872), result 3/5 then 4/5
- Practice: [Codeforces Round #441 (Div. 2)](http://codeforces.com/contest/876), result 4/6

### 12/11/2017
- Reviewed rounds #440 and #441
- Practice: [Codeforces Round #445 (Div. 2)](http://codeforces.com/contest/890), result 3/6

### 13/11/2017
- Reviewed round #445
- Attempted [Educational Codeforces Round 32 - Problem G](http://codeforces.com/contest/888/problem/G)
- Read geometry topics:
  - Line intersection and applications
  - Using geometry in Topcoder problems

### 14/11/2017
- Practice set: [CodeChef Easy Problems](https://www.codechef.com/problems/easy?sort_by=SuccessfulSubmission&sorting_order=desc)
- Target: AC in one submission within 10 minutes

### 15/11/2017 - 18/11/2017
- Challenge: 100 CodeChef easy problems
- Progress: 30/100

### 17/11/2017
- Practice: Codeforces Round #446 (Div. 2), result 3/5

### 19/11/2017
- Practice: Codeforces Round #447 (Div. 2), result 2/5 then 3/5

### 23/11/2017
- Practice: Educational Codeforces Round 33 (Div. 2), result 3/6 then 4/6

### 26/11/2017
- Practice: Codeforces Round #448 (Div. 2), result 3/5 then 4/5

### 30/11/2017
- Team session: attempted CERC'14 problems

</details>

