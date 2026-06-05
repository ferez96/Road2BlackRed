package main

/**
 * Problem 226: Invert Binary Tree
 */

import (
	"fmt"
	"slices"
)

// TreeNode represents a node in a binary tree
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func invertTree(root *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}
	return &TreeNode{
		Val:   root.Val,
		Left:  invertTree(root.Right),
		Right: invertTree(root.Left),
	}
}

func travelInOrder(root *TreeNode) []int {
	if root == nil {
		return nil
	}
	return slices.Concat(travelInOrder(root.Left), []int{root.Val}, travelInOrder(root.Right))
}

func main() {
	// Example 1: root = [4,2,7,1,3,6,9]
	// Tree structure:
	//     4
	//    / \
	//   2   7
	//  / \ / \
	// 1  3 6  9
	root1 := &TreeNode{
		Val: 4,
		Left: &TreeNode{
			Val:   2,
			Left:  &TreeNode{Val: 1},
			Right: &TreeNode{Val: 3},
		},
		Right: &TreeNode{
			Val:   7,
			Left:  &TreeNode{Val: 6},
			Right: &TreeNode{Val: 9},
		},
	}
	result1 := invertTree(root1)
	fmt.Printf("Input: root = [4,2,7,1,3,6,9]\n")
	fmt.Printf("Output: %v\n", travelInOrder(result1))
	fmt.Printf("Expected: [4,7,2,9,6,3,1]\n")
	fmt.Printf("Result root.Val: %d\n\n", result1.Val)

	// Example 2: root = [2,1,3]
	// Tree structure:
	//   2
	//  / \
	// 1   3
	root2 := &TreeNode{
		Val:   2,
		Left:  &TreeNode{Val: 1},
		Right: &TreeNode{Val: 3},
	}
	result2 := invertTree(root2)
	fmt.Printf("Input: root = [2,1,3]\n")
	fmt.Printf("Output: %v\n", travelInOrder(result2))
	fmt.Printf("Expected: [2,3,1]\n")
	fmt.Printf("Result root.Val: %d\n\n", result2.Val)

	// Example 3: root = []
	root3 := (*TreeNode)(nil)
	result3 := invertTree(root3)
	fmt.Printf("Input: root = []\n")
	fmt.Printf("Output: %v\n", travelInOrder(result3))
	fmt.Printf("Expected: []\n")
	fmt.Printf("Result is nil: %v\n\n", result3 == nil)
}
