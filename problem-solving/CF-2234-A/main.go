package main

import (
	"fmt"
	"sort"
)

// CF 2234A. Euclid, Sequence and Two Numbers
// Link: https://codeforces.com/contest/2234/problem/A
//
// Approach:
//   [write your thinking here before coding]
//
// Time:  O(nlogn)
// Space: O(logn)

func isEuclidSlice(nums []int) bool {
	if len(nums) < 2 {
		return false
	}

	x, y := nums[0], nums[1]
	for i := 2; i < len(nums); i++ {
		if nums[i] != x%y {
			return false
		}
		x, y = nums[i-1], nums[i]
	}
	return true
}

func solve(nums []int) []int {
	sort.Slice(nums, func(i, j int) bool { return nums[i] > nums[j] })
	if isEuclidSlice(nums) {
		return nums[:2]
	}
	return nil
}

func main() {
	var T int
	fmt.Scan(&T)
	for t := 0; t < T; t++ {
		var n int
		fmt.Scan(&n)
		nums := make([]int, n)
		for i := 0; i < n; i++ {
			fmt.Scan(&nums[i])
		}

		ans := solve(nums)
		if ans == nil {
			fmt.Println(-1)
		} else {
			fmt.Printf("%d %d\n", ans[0], ans[1])
		}
	}
}
