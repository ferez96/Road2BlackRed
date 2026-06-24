package main

// LC 1380. Lucky Numbers in a Matrix
// Link: https://leetcode.com/problems/lucky-numbers-in-a-matrix/
//
// Approach: precompute each row's minimum and each column's maximum in one pass,
// then collect elements that equal both the row min and the column max.
//
// Time:  O(m * n)
// Space: O(m + n)

import "fmt"

func luckyNumbers(matrix [][]int) []int {
	rowMins := make([]int, len(matrix))
	colMaxs := make([]int, len(matrix[0]))

	for i := range matrix {
		rowMins[i] = matrix[i][0]
	}

	for j := range matrix[0] {
		colMaxs[j] = matrix[0][j]
	}

	for i := range matrix {
		for j := range matrix[0] {
			if rowMins[i] > matrix[i][j] {
				rowMins[i] = matrix[i][j]
			}
			if colMaxs[j] < matrix[i][j] {
				colMaxs[j] = matrix[i][j]
			}
		}
	}

	luckies := make([]int, 0)
	for i := range matrix {
		for j := range matrix[0] {
			if matrix[i][j] == rowMins[i] && rowMins[i] == colMaxs[j] {
				luckies = append(luckies, matrix[i][j])
			}
		}
	}
	return luckies
}

func main() {
	fmt.Println(luckyNumbers([][]int{{3, 7, 8}, {9, 11, 13}, {15, 16, 17}})) // expected: [15]
	fmt.Println(luckyNumbers([][]int{{7, 8}, {1, 2}}))                       // expected: [7]
	fmt.Println(luckyNumbers([][]int{{1, 2}, {3, 4}}))                       // expected: [3]
}
