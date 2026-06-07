package main

/*
CF 2234B. Palindrome, Twelve and Two Terms
Link: https://codeforces.com/contest/2234/problem/B

Approach:
  a + b = n

  b = 12k => a + 12k = n

  Look 1: 2 paths to dig - palindrome numbers or 12's multiplier
  we can build all palidrome numbers in [0;10^18] and check if (n-a) % 12 == 0

  This is promised, we can quick estimate the number of palidrome numbers.
  0 - 9 : f[1] = 10
  11 - 99 : f[2] = 9
  1_1 - 9_9 : f[3] = 9*10 = 90
  1__1 - 9__9 : f[4] = 9*f[2] = 81
  1___1 - 9___9 : f[5] = 9*f[3] = 810
  ...
  1_..._1 - 9_..._9 : f[18] = 9*f[16] = 9^9

  => too much numbers to be stored

  Look 2: try modulo approach

  let say: n % 12 = x
  then: a % 12 = 12-x (let say: y) => a = 12k + y

  ==> only find 12 numbers to map to result
  It's is: []int64{0,1,2,3,4,5,6,7,8,9,22,11}

Time:  O(1)
Space: O(1)
*/

import "fmt"

var God = []int64{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 22, 11}

func main() {
	var t int
	fmt.Scan(&t)
	for i := 0; i < t; i++ {
		var n int64
		fmt.Scan(&n)
		a := God[n%12]
		b := n - a
		if b < 0 {
			fmt.Println(-1)
		} else {
			fmt.Printf("%d %d\n", a, b)
		}
	}

}
