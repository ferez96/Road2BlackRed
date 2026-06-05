package main

import "fmt"

/**
 * Problem 88: Merge Sorted Array
 */

func merge(nums1 []int, m int, nums2 []int, n int) {

	// Move nums1 to the end of the array to make space for answer
	for i := range m {
		nums1[m+n-1-i] = nums1[m-1-i]
	}

	// Now nums1[0:m] => nums1[n:m+n]
	i, j := n, 0
	for cur := 0; cur < m+n; cur++ {
		// fmt.Println(cur, i, j, nums1)
		if i >= m+n {
			nums1[cur] = nums2[j]
			j++
			continue
		}

		if j >= n {
			nums1[cur] = nums1[i]
			i++
			continue
		}

		if nums1[i] < nums2[j] {
			nums1[cur] = nums1[i]
			i++
		} else {
			nums1[cur] = nums2[j]
			j++
		}
	}

}

func main() {
	nums1 := []int{1, 2, 3, 0, 0, 0}
	m := 3
	nums2 := []int{2, 5, 6}
	n := 3
	merge(nums1, m, nums2, n)
	fmt.Println(nums1)
}
