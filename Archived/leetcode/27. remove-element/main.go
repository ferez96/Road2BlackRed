package main

import "fmt"

/**
 * Problem 27: Remove Element
 */

func removeElement(nums []int, val int) int {
	n := len(nums)
	k := n
	for i := 0; i < k; i++ {
		if nums[i] == val {
			for k > 0 && nums[k-1] == val {
				k--
			}
			if k > i {
				nums[i] = nums[k-1]
				k--
			}
		}
	}
	return k
}

func main() {
	nums := []int{3, 2, 2, 3}
	val := 3
	fmt.Println(removeElement(nums, val), nums)
}
