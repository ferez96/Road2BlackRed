package main

/*
LeetCode 1160. Find Words That Can Be Formed by Characters
Link: https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/

Approach:
  [write your thinking here before coding]

Time:  O(?)
Space: O(?)
*/

import "fmt"

func countCharacters(words []string, chars string) int {
	ans := 0
	have := convert(chars)
	for _, w := range words {
		if validInts(convert(w), have) {
			ans += len(w)
		}
	}
	return ans
}

func convert(word string) []int {
	count := make([]int, 26)
	for _, ch := range word {
		count[int(ch-'a')]++
	}
	return count
}

func validInts(want, have []int) bool {
	for i := 0; i < 26; i++ {
		if want[i] > have[i] {
			return false
		}
	}
	return true
}

func main() {
	fmt.Println(countCharacters(
		[]string{"cat", "bt", "hat", "tree"},
		"atach",
	)) // expected: 6

	fmt.Println(countCharacters(
		[]string{"hello", "world", "leetcode"},
		"welldonehoneyr",
	)) // expected: 10
}
