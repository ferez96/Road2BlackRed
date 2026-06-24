package main

// LC 258. Add Digits
// Link: https://leetcode.com/problems/add-digits/
//
// Approach: recursively sum digits until the result is a single digit.
// Base case: num < 10. Otherwise accumulate num % 10 while num /= 10, then recurse.
//
// Time:  O(log n) per digit-sum pass; passes are bounded by digit count
// Space: O(log n) recursion depth

import "fmt"

func addDigits(num int) int {
	if num < 10 {
		return num
	}

	newNum := 0
	for num > 0 {
		newNum += num % 10
		num /= 10
	}
	return addDigits(newNum)
}

func main() {
	fmt.Println(addDigits(38))  // expected: 2
	fmt.Println(addDigits(0))   // expected: 0
	fmt.Println(addDigits(199)) // expected: 1
}
