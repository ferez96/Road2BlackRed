package main

// LC 2465. Number of Distinct Averages
// Link: https://leetcode.com/problems/number-of-distinct-averages/
//
// Approach:
//   A sort will help this problem becomes remove first and last numbers repeatedly.
//   Count distinct can be done by push to an array, sort then count + check with the last value.
//	 With nums[i] in [0;100] we can even use hash map to count distinct.
//
// Time:  O(nlogn)
// Space: O(logn)

import (
	"fmt"
	"sort"
)

func distinctAverages(nums []int) int {
	sort.Ints(nums)
	avgs := make(map[float32]bool)
	first, last := 0, len(nums)-1
	for first < last {
		avg := float32(nums[first]+nums[last]) / 2
		avgs[avg] = true
		first++
		last--
	}
	return len(avgs)
}

func main() {
	fmt.Println(distinctAverages([]int{4, 1, 4, 0, 3, 5})) // expected: 2
	fmt.Println(distinctAverages([]int{1, 100}))           // expected: 1
}
