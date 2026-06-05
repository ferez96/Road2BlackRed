package main

/**
 * Problem 70: Climbing Stairs
 */

func Fibo(n int) int {
	fibo := make([]int, n+1)
	fibo[0] = 1
	fibo[1] = 1
	for i := 2; i < n; i++ {
		fibo[i] = fibo[i-1] + fibo[i-2]
	}
	return fibo[n]
}

func main() {
	// TODO: Add test cases and solution implementation
}
