package main

import "fmt"

/**
 * Problem 26: Remove Duplicates from Sorted Array
 */

func removeDuplicates(nums []int) int {
	n := len(nums)
	last := 0
	for i := range n {
		// skip elements have the same value
		if nums[i] == nums[last] {
			continue
		}
		// move the new value found to the head of the array, increase counter
		last++
		nums[last] = nums[i]
	}
	return last + 1
}

func main() {
	nums := []int{1, 1, 2, 3, 3, 3, 4}
	fmt.Println(removeDuplicates(nums), nums)
}
