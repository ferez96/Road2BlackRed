package main

// LC 1446. Consecutive Characters
// Link: https://leetcode.com/problems/consecutive-characters/
//
// Approach: single pass tracking the current run length of the active character.
// Reset the run when the character changes; keep the maximum run seen.
//
// Time:  O(n) | n = len(s)
// Space: O(1)

import "fmt"

func maxPower(s string) int {
	if len(s) == 0 {
		return 0
	}

	currentPower, maxPower := 1, 1
	currentChar := s[0]
	for i := 1; i < len(s); i++ {
		if s[i] != currentChar {
			currentChar = s[i]
			currentPower = 1
		} else {
			currentPower++
		}
		maxPower = max(currentPower, maxPower)
	}
	return maxPower
}

func main() {
	fmt.Println(maxPower("leetcode"))               // expected: 2
	fmt.Println(maxPower("abbcccddddeeeeedcba"))    // expected: 5
	fmt.Println(maxPower("triplepilloooooowerrrr")) // expected: 5
}
