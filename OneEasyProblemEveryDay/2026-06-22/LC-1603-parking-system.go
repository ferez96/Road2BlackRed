package main

// LC 1603. Design Parking System
// Link: https://leetcode.com/problems/design-parking-system/
//
// Approach: track remaining slots per car type; on addCar, decrement if available.
//
// Time:  O(1) per addCar
// Space: O(1)

import "fmt"

type ParkingSystem struct {
	bigSlots    int
	mediumSlots int
	smallSlots  int
}

func Constructor(big int, medium int, small int) ParkingSystem {
	return ParkingSystem{big, medium, small}
}

func (this *ParkingSystem) AddCar(carType int) bool {
	switch carType {
	case 1:
		if this.bigSlots > 0 {
			this.bigSlots--
			return true
		}
		return false
	case 2:
		if this.mediumSlots > 0 {
			this.mediumSlots--
			return true
		}
		return false
	case 3:
		if this.smallSlots > 0 {
			this.smallSlots--
			return true
		}
		return false
	default:
		return false
	}
}

func main() {
	ps := Constructor(1, 1, 0)
	fmt.Println(ps.AddCar(1)) // expected: true
	fmt.Println(ps.AddCar(2)) // expected: true
	fmt.Println(ps.AddCar(3)) // expected: false
	fmt.Println(ps.AddCar(1)) // expected: false
}
