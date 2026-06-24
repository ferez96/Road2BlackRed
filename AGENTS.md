# Competitive Programming Guidelines

Applies to all CP platforms: LeetCode, HackerRank, Codeforces, etc.

## Directory Naming

Format: `{PLATFORM}-{number}-{short-slug}`

- Platform prefixes: `LC` (LeetCode), `HR` (HackerRank), `CF` (Codeforces), `AC` (AtCoder), `CC` (CodeChef)
- Slug: 2-4 words max, kebab-case, just enough to identify — no need to spell out the full title
- Avoid collisions by including the problem number

Examples:
```
LC-1-two-sum
LC-55-jump-game
CF-1175C-kth-largest
HR-string-compress
```

## File Structure

```
LC-1-two-sum/
  main.go          ← default Go solution
  py/              ← Python variant (optional)
    main.py
  dp/              ← alternative approach variant (optional)
    main.go
```

No README. Problem link and thoughts go in the code file.

## main.go Template

```go
package main

/*
{Platform} {number}. {Title}
Link: {problem_url}

Approach:
  [write your thinking here before coding]

Time:  O(?)
Space: O(?)
*/

import "fmt"

func solution(params) returnType {
	// TODO
	return defaultValue
}

func main() {
	fmt.Println(solution(...)) // expected: ...
	fmt.Println(solution(...)) // expected: ...
}
```

## Daily workflow

```
just oeped mkdir           # create today's directory (YYYY-MM-DD/)
just oeped run             # go run today's solution
just oeped record          # record today's solve and update streak
just oeped record 2026-06-07  # record a specific date
just oeped streak          # show current streak
```

`oeped.py` in `OneEasyProblemEveryDay/` is the one-for-all helper. Add subcommands there.

## Rules

- **Do NOT implement the solution.** Scaffold only: link, empty thought block, function signature, test calls with expected values in comments.
- If the user provides a solution, write the full implementation as-is.
- User writes the solution and fills in the Approach block.
- Variants (different language or different approach) go in a subfolder, same structure.
- No README files — the problem link in the code is sufficient.
- Do NOT run `oeped.py record` or `oeped.py gha` — they write to `streak.json`.
- Do NOT run the solution code.
