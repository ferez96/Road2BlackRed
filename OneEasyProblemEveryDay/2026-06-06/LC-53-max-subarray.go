package main

/**
LC 53. Maximum Subarray
Link: https://leetcode.com/problems/maximum-subarray/

Approach:
We first try to understand the problem with a brute-force approach.
We can find all subarrays and calculate the sum of each subarray. Then return the maximum sum.
Loop through subarrays need O(n^2) and calcuolate sum need O(n) => We need O(n^3) time complexity. => This can work upto 10^3 elements.
The constraint is 10^5 elements, so we need to find a better approach.

Look 1: Sum can be calculated by subtracting the prefix sum
sum(i,j) = sum(0,j) - sum(0,i) + a[i]

This reduct the sum calc to O(1) and contribute to the time complexity, make it be O(n^2). => Not enough.

Look 2: If a segment have negacitve sum => we don't want to include it to the answer.

There are 3 position of the negative segment can be:
- begin
- end
- middle

Look 2.1: this problem can reverse all the elements and the problem is the same. => begin and end position is the same

Let's say we choose the direction from start to end of the array.
Let's say we have a negative segment at (i,j)
The only reason we should choose (i,j) is there is another segment inside (0,i-1), called x, that sum(x,j) > 0 => then we can continue with summing.

This make a statement: if any segment sum(0,x) < 0 => ignore them, they will never be in the answer.

Counter: if a sub-segment in (0,x) can be the best answer, we should save it.

The above looks result to an approach: loop through the array, calculate the sum from the beginning. Keep the max sum. If at any point, the sum be negative, reset to 0.

Time:  O(n) - each element walked once
Space: O(1) - no extra array needed
*/

import "fmt"

const MinElementValue = -10000
const MaxElementValue = 10000

// len(nums) must > 0
func maxSubArray(nums []int) int {
	// If the array is all negative, we select the max element as the result
	maxNum := maxElement(nums)
	if maxNum < 0 {
		return maxNum
	}

	maxSum := 0
	currentSum := 0
	for _, num := range nums {
		currentSum += num
		maxSum = max(maxSum, currentSum)		
		if currentSum < 0 {
			currentSum = 0
		}
	}
	return maxSum
}

// len(nums) must > 0
func maxElement(nums []int) int {
	maxNum := MinElementValue-1
	for _, num := range nums {
		maxNum = max(maxNum, num)
	}
	return maxNum
}

func main() {
	fmt.Println(maxSubArray([]int{-2, 1, -3, 4, -1, 2, 1, -5, 4})) // expected: 6
	fmt.Println(maxSubArray([]int{1}))                               // expected: 1
	fmt.Println(maxSubArray([]int{5, 4, -1, 7, 8}))                 // expected: 23
}
