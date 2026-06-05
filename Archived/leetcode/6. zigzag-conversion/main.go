package main

/**
 * Problem 6: Zigzag Conversion
 */

import (
	"fmt"
)

func convert(s string, numRows int) string {
	if len(s) == 1 || numRows == 1 {
		return s
	}
	var n = len(s)
	var C = 2 * (numRows - 1)
	var res = make([]byte, len(s))
	var cur = 0
	for i := 1; i <= numRows; i++ {
		if i == 1 || i == numRows {
			for k := 0; k*C+i <= n; k++ {
				res[cur] = s[k*C+i-1]
				cur++
			}
		} else {
			for k := 0; k*C+1-(i-1) <= n; k++ {
				var pos1, pos2 = k*C + 1 - (i - 1), k*C + 1 + (i - 1)
				if pos1 > 0 {
					res[cur] = s[pos1-1]
					cur++
				}
				if pos2 <= n {
					res[cur] = s[pos2-1]
					cur++
				}
			}
		}
	}
	return string(res)
}

func main() {
	// Example 1: s = "PAYPALISHIRING", numRows = 3
	s1 := "PAYPALISHIRING"
	numRows1 := 3
	result1 := convert(s1, numRows1)
	fmt.Printf("Input: s = %q, numRows = %d\n", s1, numRows1)
	fmt.Printf("Output: %q\n", result1)
	fmt.Printf("Expected: %q\n\n", "PAHNAPLSIIGYIR")

	// Example 2: s = "PAYPALISHIRING", numRows = 4
	s2 := "PAYPALISHIRING"
	numRows2 := 4
	result2 := convert(s2, numRows2)
	fmt.Printf("Input: s = %q, numRows = %d\n", s2, numRows2)
	fmt.Printf("Output: %q\n", result2)
	fmt.Printf("Expected: %q\n\n", "PINALSIGYAHRPI")

	// Example 3: s = "A", numRows = 1
	s3 := "A"
	numRows3 := 1
	result3 := convert(s3, numRows3)
	fmt.Printf("Input: s = %q, numRows = %d\n", s3, numRows3)
	fmt.Printf("Output: %q\n", result3)
	fmt.Printf("Expected: %q\n\n", "A")
}
