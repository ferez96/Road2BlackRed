package main

// LC 3945. Digit Frequency Score
// Link: https://leetcode.com/problems/digit-frequency-score/
//
// Approach: d * freq(d) summed over all digits is just the sum of every digit in n.
// Extract each digit with n % 10 and shrink n with n /= 10.
//
// Time:  O(log n)
// Space: O(1)

import "fmt"

func digitFrequencyScore(n int) int {
	score := 0
	for n > 0 {
		score += n % 10
		n /= 10
	}
	return score
}

func main() {
	fmt.Println(digitFrequencyScore(122)) // expected: 5
	fmt.Println(digitFrequencyScore(101)) // expected: 2
}
