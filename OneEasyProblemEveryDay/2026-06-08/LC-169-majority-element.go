package main

// LC 169. Majority Element
// Link: https://leetcode.com/problems/majority-element/
//
// Approach:
//   Using a map to count by number. The loop one time on the map to check which is the asnwer.
//
// Time: O(n)
// Space: O(n)

import "fmt"

func majorityElement(nums []int) int {
	n := len(nums)
	if n == 0 {
		return 0
	}

	numCounts := make(map[int]int)
	for _, num := range nums {
		numCounts[num]++
	}

	majorNum := nums[0]
	for num, count := range numCounts {
		if count > numCounts[majorNum] {
			majorNum = num
		}
	}
	return majorNum
}

func main() {
	fmt.Println(majorityElement([]int{3, 2, 3}))                 // expected: 3
	fmt.Println(majorityElement([]int{2, 2, 1, 1, 1, 2, 2})) // expected: 2
}
