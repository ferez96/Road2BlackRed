package main

/*
LC 2317. Maximum XOR After Operations
Link: https://leetcode.com/problems/maximum-bitwise-xor-after-rearrangement/

Approach:

Re-phase the problem: in every t's mutation x => return max(s XOR x)

Solution space: n! (n = len(s) == len(t))
1 <= n == s.length == t.length <= 2 * 10^5 => impossible to brute-force

Look 1:
If (s[0] XOR x[0] == 1) => x[0] is optimal.
If (s[i] XOR x[i] == 0) => should find another bit to make (s[i] XOR x[i] == 1) if possible

This guide us to a greedy solution:
From left to right of s => attempt to make biggest possible outcome

Look 2: (Naturally)

We don't need the whole t. We just need count 0s & 1s. Reduce each when used.

Time:  O(n)
Space: O(1)
*/

import (
	"fmt"
	"strings"
)

func maximumXor(s string, t string) string {
	availableBits := make([]int, 2) // 0 & 1
	for _, tRune := range t {
		availableBits[toBit(tRune)]++
	}

	solBuilder := strings.Builder{}
	for _, sRune := range s {
		sBit := toBit(sRune)
		tBit := sBit ^ 1 // tb | sb | sb = expected

		if availableBits[tBit] == 0 {
			tBit = sBit
		}

		availableBits[tBit]--
		solBuilder.WriteRune(toRune(sBit ^ tBit))
	}
	return solBuilder.String()
}

func toBit(ch rune) int {
	return int(ch - '0')
}

func toRune(bit int) rune {
	return rune(bit + '0')
}

func main() {
	fmt.Println(maximumXor("101", "011"))   // expect: 110
	fmt.Println(maximumXor("0110", "1110")) // expect: 1101
	fmt.Println(maximumXor("110011", "101010"))
	fmt.Println(maximumXor("11100011", "00110011"))
}
