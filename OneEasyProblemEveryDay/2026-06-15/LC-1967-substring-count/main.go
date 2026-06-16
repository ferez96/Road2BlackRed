package main

// LC 1967. Number of Strings That Appear as Substrings in Word
// Link: https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/
//
// Approach: generate all substrings of word and store them in a hash set.
// Each substring slice is O(1), but inserting a string key into a map
// requires hashing all characters in the substring.
//
// Time:
//   Build hash set: O(N^3)
//   Pattern lookup: O(P * N)
//   Total: O(N^3 + P*N)
//
// Space:
//   O(N^2) hash set entries

import "fmt"

func numOfStrings(patterns []string, word string) int {
	dict := make(map[string]bool)
	for i := 0; i < len(word); i++ {
		for j := i + 1; j <= len(word); j++ {
			dict[word[i:j]] = true
		}
	}

	cnt := 0
	for _, pattern := range patterns {
		if dict[pattern] {
			cnt++
		}
	}
	return cnt
}

func main() {
	fmt.Println(numOfStrings([]string{"a", "abc", "bc", "d"}, "abc")) // expected: 3
	fmt.Println(numOfStrings([]string{"a", "b", "c"}, "aaaaabbbbb"))  // expected: 2
	fmt.Println(numOfStrings([]string{"a", "a", "a"}, "ab"))          // expected: 3
}
