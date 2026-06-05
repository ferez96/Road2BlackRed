/*
 * Problem: Longest Palindromic Substring
 *
 * Given a string s, return the longest palindromic substring in s.
 * A palindrome is a string that reads the same backward as forward.
 */
package main

import "fmt"

func main() {
	s := "aacabdkacaa"

	fmt.Println("Input:", s)
	fmt.Println("O(n^2) Center Expansion:", Do(s))
	fmt.Println("O(n^2) Dynamic Programming:", DoDP(s))
	fmt.Println("O(n) Manacher's Algorithm:", DoManacher(s))
	fmt.Println("O(n^3) Brute Force:", Do2(s))
}

// best returns the longer of two strings. Used to track the longest palindrome found.
func best(a, b string) string {
	if len(b) > len(a) {
		return b
	} else {
		return a
	}
}

/** Solution O(n^3) - Brute Force Approach
 *
 * This approach checks every possible substring to see if it's a palindrome.
 * Time Complexity: O(n^3) - O(n^2) for all substrings, O(n) to check each one
 * Space Complexity: O(1)
 */

// IsPalidromic checks if a string is a palindrome by comparing characters
// from both ends moving towards the center.
func IsPalidromic(s string) bool {
	for i := 0; i <= len(s)/2; i++ {
		if s[i] != s[len(s)-i-1] {
			return false
		}
	}
	return true
}

// Do2 finds the longest palindromic substring using brute force.
// It iterates through all possible substrings (i to j) and checks if each is palindromic.
// Keeps track of the longest palindrome found so far.
func Do2(s string) string {
	ans := string(s[0])
	for i := 0; i < len(s); i++ {
		for j := i + 1; j < len(s); j++ {
			substr := s[i : j+1]
			if IsPalidromic(substr) {
				ans = best(ans, substr)
			}
		}
	}
	return ans
}

/** Solution O(n^2) - Center Expansion Approach
 *
 * This approach uses the key insight that every palindrome expands around a center.
 * For a string of length n, there are 2n-1 possible centers:
 *   - n centers for odd-length palindromes (single character)
 *   - n-1 centers for even-length palindromes (between two characters)
 *
 * Time Complexity: O(n^2) - O(n) centers, O(n) expansion for each
 * Space Complexity: O(1)
 */

// LongestPalindromicSubstringWithCenter finds the longest palindrome expanding
// from a given center position. It handles both odd and even length palindromes:
//   - For odd: pl == pr (e.g., "aba" expands from center 'b')
//   - For even: pl == pr-1 (e.g., "abba" expands from between two 'b's)
//
// The function expands outward (left and right) as long as characters match.
func LongestPalindromicSubstringWithCenter(s string, pl, pr int) string {
	result := ""
	for i, j := pl, pr; i >= 0 && j < len(s); i, j = i-1, j+1 {
		if s[i] == s[j] {
			char := string(s[i])
			if i == j { // first loop only (odd-length palindrome starting at single character)
				result = char
				continue
			}

			// Expand palindrome by adding matching characters on both sides
			result = char + result + char
		} else {
			// stop with the first mismatch
			break
		}
	}
	return result
}

// Do finds the longest palindromic substring using center expansion.
// For each position i in the string, it checks two types of centers:
//  1. Odd-length: center at position i (candidate1)
//  2. Even-length: center between positions i-1 and i (candidate2)
//
// Example: For "aba", at i=1:
//   - candidate1: expands from 'b' -> "aba"
//   - candidate2: expands from between 'a' and 'b' -> "a"
func Do(s string) string {
	if len(s) == 1 {
		return s
	}

	bestAns := ""
	for i := 1; i < len(s); i++ {
		// Check for odd-length palindrome centered at position i
		candidate1 := LongestPalindromicSubstringWithCenter(s, i, i)
		bestAns = best(bestAns, candidate1)
		// Check for even-length palindrome centered between positions i-1 and i
		candidate2 := LongestPalindromicSubstringWithCenter(s, i-1, i)
		bestAns = best(bestAns, candidate2)
	}

	return bestAns
}

/** Solution O(n^2) - Dynamic Programming Approach
 *
 * Uses a DP table where dp[i][j] indicates if substring s[i:j+1] is a palindrome.
 * Key insight: s[i:j+1] is a palindrome if s[i] == s[j] and s[i+1:j] is also a palindrome.
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(n^2) - can be optimized to O(n) by using only previous row
 */

// DoDP finds the longest palindromic substring using dynamic programming.
// Builds a table where dp[i][j] = true if s[i:j+1] is a palindrome.
func DoDP(s string) string {
	n := len(s)
	if n == 0 {
		return ""
	}

	// dp[i][j] = true if substring s[i:j+1] is a palindrome
	dp := make([][]bool, n)
	for i := range dp {
		dp[i] = make([]bool, n)
	}

	start, maxLen := 0, 1

	// Every single character is a palindrome
	for i := 0; i < n; i++ {
		dp[i][i] = true
	}

	// Check for palindromes of length 2
	for i := 0; i < n-1; i++ {
		if s[i] == s[i+1] {
			dp[i][i+1] = true
			start = i
			maxLen = 2
		}
	}

	// Check for palindromes of length 3 and more
	// length is the length of the substring we're checking
	for length := 3; length <= n; length++ {
		// i is the starting index
		for i := 0; i < n-length+1; i++ {
			j := i + length - 1 // ending index

			// s[i:j+1] is a palindrome if:
			// 1. The first and last characters match (s[i] == s[j])
			// 2. The inner substring s[i+1:j] is also a palindrome
			if s[i] == s[j] && dp[i+1][j-1] {
				dp[i][j] = true
				start = i
				maxLen = length
			}
		}
	}

	return s[start : start+maxLen]
}

/** Solution O(n) - Manacher's Algorithm (Optimal)
 *
 * This is the most efficient algorithm for finding the longest palindromic substring.
 * It uses the key insight of reusing information about previously found palindromes.
 *
 * Algorithm steps:
 * 1. Transform string to handle even-length palindromes (insert separators, e.g., "aba" -> "#a#b#a#")
 * 2. Maintain a center and right boundary of the rightmost palindrome found
 * 3. For each position, use mirror property to get initial palindrome length
 * 4. Expand from the initial length to find the actual palindrome
 *
 * Time Complexity: O(n) - each character is expanded at most once
 * Space Complexity: O(n) - for the transformed string and radius array
 */

// DoManacher finds the longest palindromic substring using Manacher's algorithm.
// This is the optimal O(n) solution.
func DoManacher(s string) string {
	if len(s) == 0 {
		return ""
	}

	// Transform string: "aba" -> "^#a#b#a#$"
	// Using ^ and $ as sentinels to avoid bounds checking
	transformed := make([]byte, 0, 2*len(s)+3)
	transformed = append(transformed, '^')
	for i := 0; i < len(s); i++ {
		transformed = append(transformed, '#')
		transformed = append(transformed, s[i])
	}
	transformed = append(transformed, '#')
	transformed = append(transformed, '$')

	n := len(transformed)
	// P[i] stores the radius of the palindrome centered at position i
	P := make([]int, n)
	center, right := 0, 0
	maxCenter, maxRadius := 0, 0

	for i := 1; i < n-1; i++ {
		// Use mirror property: if i is within the rightmost palindrome,
		// we can use the mirror position to get initial palindrome length
		if i < right {
			mirror := 2*center - i
			// P[mirror] might extend beyond the current palindrome boundary,
			// so we take the minimum
			P[i] = min(right-i, P[mirror])
		}

		// Try to expand palindrome centered at i
		// transformed[i + P[i] + 1] and transformed[i - P[i] - 1] are symmetric positions
		for transformed[i+(P[i]+1)] == transformed[i-(P[i]+1)] {
			P[i]++
		}

		// Update the rightmost palindrome if we found one that extends further
		if i+P[i] > right {
			center = i
			right = i + P[i]
		}

		// Track the longest palindrome found
		if P[i] > maxRadius {
			maxRadius = P[i]
			maxCenter = i
		}
	}

	// Extract the original substring from the transformed string
	// maxCenter is the center in transformed string, maxRadius is the radius
	// Original start = (maxCenter - maxRadius) / 2
	// Original length = maxRadius
	start := (maxCenter - maxRadius) / 2
	return s[start : start+maxRadius]
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
