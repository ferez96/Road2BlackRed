/*
Problem Link:  https://www.hackerrank.com/challenges/solve-me-first/problem
Notes:
- Should declare requirements as constants
  - Because it's easy to make mistakes if the requirements are not clear
  - Define the constraints with meaningful names helps prevent mistakes.
  - To avoid magic numbers.

- Should print error messages to stderr.
- A reusable validation function could help readability and maintainability.
- Should not use unusual types like uint16, uint32, etc.
  - Because it requires fully understanding the operation under the hood.
  - Saving a few bytes is not worth the complexity. Or worse, it could lead to bugs.
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

func sum(a int, b int) int {
	return a + b
}

func _validInput(x int) bool {
	return x >= minValue && x <= maxValue
}

func main() {
	var a, b int
	if _, err := fmt.Scanf("%d\n%d", &a, &b); err != nil {
		fmt.Fprintln(os.Stderr, "Error reading input:", err)
		os.Exit(1)
	}
	if !_validInput(a) || !_validInput(b) {
		fmt.Fprintln(os.Stderr, "Input out of range")
		os.Exit(1)
	}
	fmt.Println(sum(a, b))
}
