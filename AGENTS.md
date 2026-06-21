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

## Rules

- **Do NOT implement the solution.** Scaffold only: link, empty thought block, function signature, test calls with expected values in comments.
- User writes the solution and fills in the Approach block.
- Variants (different language or different approach) go in a subfolder, same structure.
- No README files — the problem link in the code is sufficient.
