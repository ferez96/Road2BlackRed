package main

// LC 1662. Check If Two String Arrays are Equivalent
// Link: https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
//
// Approach: Use 2 pointers to travel 2 word arrays simultaneously
//
// Time:  O(n)
// Space: O(1)

import "fmt"

func arrayStringsAreEqual(word1 []string, word2 []string) bool {
	wordIndex1, wordIndex2 := 0, 0
	subStrIndex1, subStrIndex2 := 0, 0
	for wordIndex1 < len(word1) && wordIndex2 < len(word2) {
		subStr1, subStr2 := word1[wordIndex1], word2[wordIndex2]
		for subStrIndex1 < len(subStr1) && subStrIndex2 < len(subStr2) {
			// fmt.Println(string(subStr1[subStrIndex1]), string(subStr2[subStrIndex2]))
			if subStr1[subStrIndex1] != subStr2[subStrIndex2] {
				return false
			}
			subStrIndex1++
			subStrIndex2++
		}
		if subStrIndex1 == len(subStr1) {
			wordIndex1++
			subStrIndex1 = 0
		}
		if subStrIndex2 == len(subStr2) {
			wordIndex2++
			subStrIndex2 = 0
		}
	}
	if wordIndex1 != len(word1) || wordIndex2 != len(word2) || subStrIndex1 != 0 || subStrIndex2 != 0 {
		return false
	}
	return true
}

func main() {
	fmt.Println(arrayStringsAreEqual([]string{"ab", "c"}, []string{"a", "bc"}))           // expected: true
	fmt.Println(arrayStringsAreEqual([]string{"a", "cb"}, []string{"ca", "b"}))           // expected: false
	fmt.Println(arrayStringsAreEqual([]string{"abc", "d", "defg"}, []string{"abcddefg"})) // expected: true
}
