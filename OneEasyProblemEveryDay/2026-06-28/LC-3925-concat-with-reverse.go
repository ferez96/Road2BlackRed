package main

/*
LC 3925. Concatenate Array With Reverse
Link: https://leetcode.com/problems/concatenate-array-with-reverse/

Approach:
  Allocate result of length 2n, copy nums into first half,
  then fill second half with nums in reverse order.

Time:  O(n)
Space: O(n)
*/

import "fmt"

func concatWithReverse(nums []int) []int {
	result := make([]int, 2*len(nums))
	copy(result, nums)
	for i := len(nums) - 1; i >= 0; i-- {
		result[2*len(nums)-i-1] = nums[i]
	}
	return result
}

func main() {
	fmt.Println(concatWithReverse([]int{1, 2, 3}))    // expected: [1 2 3 3 2 1]
	fmt.Println(concatWithReverse([]int{5, 4, 3, 2})) // expected: [5 4 3 2 2 3 4 5]
}
