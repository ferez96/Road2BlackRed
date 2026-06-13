package main

// LC 2210. Count Hills and Valleys in an Array
// Link: https://leetcode.com/problems/count-hills-and-valleys-in-an-array/
//
// Approach:
// [write your thinking here before coding]
//
// Time: O(?)
// Space: O(?)

import "fmt"

func countHillValley(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	trend := 0
	currentHeight := nums[0]
	cnt := 0

	for i := 1; i < len(nums); i++ {
		// fmt.Println(i, currentHeight, nums[i], trend, nums[i] - currentHeight, cnt)
		if trend*(nums[i]-currentHeight) < 0 {
			cnt++
		}
		if (nums[i] - currentHeight) != 0 {
			trend = nums[i] - currentHeight
		}
		currentHeight = nums[i]
	}

	return cnt
}

func main() {
	fmt.Println(countHillValley([]int{2, 4, 1, 1, 6, 5})) // expected: 3
	fmt.Println(countHillValley([]int{6, 6, 5, 5, 4, 1})) // expected: 0
}
