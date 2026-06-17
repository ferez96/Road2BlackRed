package main

// LC 1502. Can Make Arithmetic Progression From Sequence
// Link: https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/
//
// Approach: sort the array, then check that every adjacent pair has the same difference.
// Any valid rearrangement into an AP must match the sorted order.
//
// Time:  O(n log n) | n = len(arr)
// Space: O(1)

import (
	"fmt"
	"sort"
)

func canMakeArithmeticProgression(arr []int) bool {
	if len(arr) < 2 {
		return true
	}
	sort.Ints(arr)
	diff := arr[1] - arr[0]
	for i := 2; i < len(arr); i++ {
		if arr[i]-arr[i-1] != diff {
			return false
		}
	}
	return true
}

func main() {
	fmt.Println(canMakeArithmeticProgression([]int{3, 5, 1})) // expected: true
	fmt.Println(canMakeArithmeticProgression([]int{1, 2, 4})) // expected: false
}
