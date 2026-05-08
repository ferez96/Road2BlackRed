package main

import "fmt"

func answer(input any) any {
	return nil
}

func main() {
	testcases := []int{1, 2, 3, 4, 5}
	for i, testcase := range testcases {
		fmt.Printf("Case #%d: %v\n", i+1, answer(testcase))
	}
}
