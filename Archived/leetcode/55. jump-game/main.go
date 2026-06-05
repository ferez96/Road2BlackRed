package main

/**
 * Problem 55: Jump Game
 */

import (
	"fmt"
)

func canJump(nums []int) bool {
	var n = len(nums)
	var maxReachable = 1
	for i := 0; i < maxReachable && i < n; i++ {
		maxReachable = max(maxReachable, (i+1)+nums[i])
	}
	return maxReachable >= n
}

func main() {
	// Example 1: nums = [2,3,1,1,4]
	nums1 := []int{2, 3, 1, 1, 4}
	result1 := canJump(nums1)
	fmt.Printf("Input: %v\n", nums1)
	fmt.Printf("Output: %v\n", result1)
	fmt.Printf("Expected: true\n\n")

	// Example 2: nums = [3,2,1,0,4]
	nums2 := []int{3, 2, 1, 0, 4}
	result2 := canJump(nums2)
	fmt.Printf("Input: %v\n", nums2)
	fmt.Printf("Output: %v\n", result2)
	fmt.Printf("Expected: false\n\n")

	nums3 := []int{2, 0, 0}
	fmt.Println(canJump(nums3))

	fmt.Println(canJump([]int{3, 2, 1, 0, 4}))
}
