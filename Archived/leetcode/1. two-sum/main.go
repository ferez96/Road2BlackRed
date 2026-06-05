package main

import (
	"fmt"
	"sort"
)

func main() {
	nums := []int{2, 1000, 7, 11, 15}
	target := 9
	fmt.Println(twoSum(nums, target))
}

type Ref struct {
	Value int
	Index int
}

func ToRefArray(nums []int) []Ref {
	result := make([]Ref, 0, len(nums))
	for i, v := range nums {
		result = append(result, Ref{v, i})
	}
	return result
}

func BinarySearch(refs []Ref, left, right int, value int, skipIndex int) int {
	if left > right {
		return -1
	}
	mid := (left + right) / 2
	if refs[mid].Value == value && refs[mid].Index != skipIndex {
		return refs[mid].Index
	}
	if refs[mid].Value < value {
		return BinarySearch(refs, mid+1, right, value, skipIndex)
	}
	return BinarySearch(refs, left, mid-1, value, skipIndex)
}

func twoSum(nums []int, target int) []int {
	refs := ToRefArray(nums)
	sort.Slice(refs, func(i, j int) bool {
		return refs[i].Value < refs[j].Value
	})
	for i, value := range nums {
		expected := target - value
		if j := BinarySearch(refs, 0, len(refs)-1, expected, i); j != -1 {
			return []int{i, j}
		}
	}
	return nil
}
