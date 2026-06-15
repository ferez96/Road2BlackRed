package main

// LC 1967. Number of Strings That Appear as Substrings in Word
// Link: https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/
//
// Approach: store all substrings in a hash map and look up to count valid patterns
//
// Time: O(N^3)
// Space: O(N^2)

import "fmt"

func numOfStrings(patterns []string, word string) int {
	dict := make(map[string]bool)
	for i := 0; i < len(word); i++ {
		for j := i+1; j <= len(word); j++ {
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
