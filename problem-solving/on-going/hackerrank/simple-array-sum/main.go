/*
Problem Link:  https://www.hackerrank.com/challenges/simple-array-sum/problem
*/

// code
package main

import (
	"fmt"
	"os"
)

const (
	minValue = 1
	maxValue = 1000
)

func _validInput(x int) bool {
	return x >= minValue && x <= maxValue
}

func _readInt() int {
	// TODO: handle too long without input
	var x int
	if _, err := fmt.Scan(&x); err != nil {
		fmt.Fprintln(os.Stderr, "Error reading input:", err)
		os.Exit(1)
	}
	if !_validInput(x) {
		fmt.Fprintln(os.Stderr, "Input out of range")
		os.Exit(1)
	}
	return x
}

func _passNewline() {
	var x string
	if _, err := fmt.Scan(&x); err != nil {
		fmt.Fprintln(os.Stderr, "Error reading input:", err)
		os.Exit(1)
	}
	if x != "\n" {
		fmt.Fprintln(os.Stderr, "Expected newline")
		os.Exit(1)
	}
}

func _readArray(n int) []int {
	arr := make([]int, n)
	for i := range arr {
		arr[i] = _readInt()
	}
	return arr
}

func _calculateSum(arr []int) int {
	sum := 0
	for _, v := range arr {
		sum += v
	}
	return sum
}

func main() {
	// input: read the array from the standard input
	n := _readInt()
	// _passNewline()
	arr := _readArray(n)
	// calculate the sum of the array
	sum := _calculateSum(arr)
	// output: print the sum to the standard output
	fmt.Println(sum)
}
