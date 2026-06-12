package main

// LC 1260. Shift 2D Grid
// Link: https://leetcode.com/problems/shift-2d-grid/
//
// Approach: If we platten the matrix to array, the matrix shift actually shift the array. We can go to final state directly
// We can trade space complexity with code complexity with using math calculations
//
// Time: O(n)
// Space: O(n)

import "fmt"

func shiftGrid(grid [][]int, k int) [][]int {
	if len(grid) == 0 || len(grid[0]) == 0 {
		return nil
	}
	height, width := len(grid), len(grid[0])
	size := height * width
	arr := make([]int, size)
	for row := range height {
		for col := range width {
			arr[(toArrayIndex(row, col, height, width)+k)%size] = grid[row][col]
		}
	}
	for idx := range size {
		row, col := toMatrixIndex(idx, height, width)
		grid[row][col] = arr[idx]
	}
	return grid
}

func toArrayIndex(row, col int, height, width int) int {
	return row*width + col
}

func toMatrixIndex(idx int, height, width int) (int, int) {
	row := idx / width
	col := idx - width*row
	return row, col
}

func main() {
	fmt.Println(shiftGrid([][]int{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, 1))                             // expected: [[9 1 2] [3 4 5] [6 7 8]]
	fmt.Println(shiftGrid([][]int{{3, 8, 1, 9}, {19, 7, 2, 5}, {4, 6, 11, 0}, {12, 0, 21, 13}}, 4)) // expected: [[12 0 21 13] [13 0 11 4] [9 19 7 2] [4 6 11 0]]
	fmt.Println(shiftGrid([][]int{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, 9))                             // expected: [[1 2 3] [4 5 6] [7 8 9]]
}
