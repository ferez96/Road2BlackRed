package main

// LC 859. Buddy Strings
// Link: https://leetcode.com/problems/buddy-strings/
//
// Approach:
//   4 cases handling:
//		- if the length is not the same => fail
//		- if the strings have only 2 diff characters => try swap them and check
//		- if the strings are identical => swap any pair of positions that have the same character = keep the string after swap
//		- if the strings have non-zero-or-two diff characters => unable to make any valid operation
//
// Time:  O(n) | n = len(s)
// Space: O(n) | n = len(s)

import "fmt"

func buddyStrings(s string, goal string) bool {
	if len(s) != len(goal) {
		return false
	}
	diffIndexes := getDiffIndexes(s, goal)
	switch len(diffIndexes) {
	case 2:
		i, j := diffIndexes[0], diffIndexes[1]
		if s[i] == goal[j] && s[j] == goal[i] {
			// swap i <=> j is correct
			return true
		} else {
			return false
		}
	case 0:
		// two string is identical, check any
		if hasRepeatedCharacter(s) {
			// swap keep the string remains the same
			return true
		} else {
			return false
		}
	default:
		return false
	}
}

// precondidtion: len(s1) == len(s2)
func getDiffIndexes(s1, s2 string) []int {
	indexes := make([]int, 0)
	for i := range len(s1) {
		if s1[i] != s2[i] {
			indexes = append(indexes, i)
		}
	}
	return indexes
}

func hasRepeatedCharacter(s string) bool {
	dict := make(map[rune]bool)
	for _, ch := range s {
		if dict[ch] {
			return true
		} else {
			dict[ch] = true
		}
	}
	return false
}

func main() {
	fmt.Println(buddyStrings("ab", "ba")) // expected: true
	fmt.Println(buddyStrings("ab", "ab")) // expected: false
	fmt.Println(buddyStrings("aa", "aa")) // expected: true
}
