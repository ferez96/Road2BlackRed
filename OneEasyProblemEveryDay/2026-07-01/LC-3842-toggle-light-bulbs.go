package main

/*
LC 3842. Toggle Light Bulbs
Link: https://leetcode.com/problems/toggle-light-bulbs/

Approach:
  Hash Table — track toggle state per bulb (0/1), collect all that end up on.

Time:  O(n)
Space: O(n)
*/

import "fmt"

func toggleLightBulbs(bulbs []int) []int {
	bulbStates := make([]int, 100+1)
	for _, bulb := range bulbs {
		bulbStates[bulb] = 1 - bulbStates[bulb]
	}
	lightingBulbs := make([]int, 0, 100)
	for i := 1; i <= 100; i++ {
		if bulbStates[i] == 1 {
			lightingBulbs = append(lightingBulbs, i)
		}
	}
	return lightingBulbs
}

func main() {
	fmt.Println(toggleLightBulbs([]int{1, 2, 1, 3})) // expected: [2 3]
	fmt.Println(toggleLightBulbs([]int{1, 1, 1}))     // expected: [1]
}
