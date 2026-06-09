package main

// LC 1295. Find Numbers with Even Number of Digits
// Link: https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
//
// Approach:
//   Brute-force: loop through the array and check every number for the condition.
//
// Time: O(5)*O(n) = O(n)
// Space: O(1)

import "fmt"

func isEvenLenNumber(num int) bool {
	cnt := 0
	for num > 0 {
		num /= 10
		cnt++
	}
	return cnt%2 == 0
}

func findNumbers(nums []int) int {
	cnt := 0
	for _, num := range nums {
		if isEvenLenNumber(num) {
			cnt++
		}
	}
	return cnt
}

func main() {
	fmt.Println(findNumbers([]int{12, 345, 2, 6, 7896})) // expected: 2
	fmt.Println(findNumbers([]int{555, 901, 482, 1771})) // expected: 1
}
