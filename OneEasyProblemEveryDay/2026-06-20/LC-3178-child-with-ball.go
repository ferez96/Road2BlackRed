package main

// LC 3178. Find the Child Who Has the Ball After K Seconds
// Link: https://leetcode.com/problems/find-the-child-who-has-the-ball-after-k-seconds/
//
// Approach: the ball travels n-1 steps per leg; count full legs to get direction,
// then map the remaining steps from the current end (0 or n-1).
//
// Time:  O(1)
// Space: O(1)

import "fmt"

func numberOfChild(n int, k int) int {
	rounds := k / (n - 1)
	direction := rounds % 2
	steps := k % (n - 1)
	if direction == 0 {
		return steps
	}
	return n - 1 - steps
}

func main() {
	fmt.Println(numberOfChild(3, 5)) // expected: 1
	fmt.Println(numberOfChild(5, 6)) // expected: 2
	fmt.Println(numberOfChild(4, 2)) // expected: 2
}
