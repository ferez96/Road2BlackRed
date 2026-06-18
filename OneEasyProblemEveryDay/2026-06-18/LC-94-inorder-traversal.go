package main

// LC 94. Binary Tree Inorder Traversal
// Link: https://leetcode.com/problems/binary-tree-inorder-traversal/
//
// Approach: recursive inorder — collect left subtree, append root, then right subtree.
// Each call merges child results into a single slice.
//
// Time:  O(n) | n = number of nodes
// Space: O(n) for output + O(h) recursion stack

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func inorderTraversal(root *TreeNode) []int {
	if root == nil {
		return nil
	}
	left := inorderTraversal(root.Left)
	right := inorderTraversal(root.Right)
	ans := append(left, root.Val)
	for _, val := range right {
		ans = append(ans, val)
	}
	return ans
}

func main() {
	// [1,null,2,3] -> [1,3,2]
	root1 := &TreeNode{
		Val: 1,
		Right: &TreeNode{
			Val:  2,
			Left: &TreeNode{Val: 3},
		},
	}
	fmt.Println(inorderTraversal(root1)) // expected: [1 3 2]

	fmt.Println(inorderTraversal(nil)) // expected: []

	fmt.Println(inorderTraversal(&TreeNode{Val: 1})) // expected: [1]
}
