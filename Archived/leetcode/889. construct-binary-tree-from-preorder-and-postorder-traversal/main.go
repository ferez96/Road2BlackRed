package main

/**
 * Problem 889: Construct Binary Tree from Preorder and Postorder Traversal
 *
 * Given two integer arrays, preorder and postorder where preorder is the preorder traversal
 * of a binary tree of distinct values and postorder is the postorder traversal of the same tree,
 * reconstruct and return the binary tree.
 *
 * If there exist multiple answers, you can return any of them.
 *
 * Approach:
 * The key insight is that:
 * - In preorder: root appears first, then left subtree, then right subtree
 * - In postorder: left subtree appears first, then right subtree, then root
 *
 * Algorithm:
 * 1. The root is always preorder[0] (first in preorder) and postorder[n-1] (last in postorder)
 * 2. For a node with value 'rootVal':
 *    - Left child: The next unvisited element in preorder (preorder[preIndex+1])
 *    - Right child: The previous unvisited element in postorder (postorder[postIndex-1])
 * 3. We use tracking arrays (visitedPre, visitedPost) to mark visited nodes
 * 4. Recursively build left and right subtrees
 *
 * Example:
 *   Preorder:  [1, 2, 4, 5, 3, 6, 7]
 *   Postorder: [4, 5, 2, 6, 7, 3, 1]
 *
 *   Root = 1 (first in preorder, last in postorder)
 *   - Left child = 2 (next in preorder after 1)
 *   - Right child = 3 (previous in postorder before 1)
 *
 * Time Complexity: O(n^2) - for each node, we do a linear search to find indices
 * Space Complexity: O(n) - for the tracking arrays and recursion stack
 */

import (
	"fmt"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func main() {
	preorder := []int{1, 2, 4, 5, 3, 6, 7}
	postorder := []int{4, 5, 2, 6, 7, 3, 1}
	root := ConstructTree(preorder, postorder)

	// Print to console
	PrintTree(root)
}

func PrintTree(root *TreeNode) {
	if root == nil {
		fmt.Println("Tree is empty")
		return
	}
	printTreeHelper(root, "", true, false)
}

func printTreeHelper(node *TreeNode, prefix string, isLast bool, hasNonLastAncestor bool) {
	if node == nil {
		return
	}

	// fmt.Println("Node:", node.Val, valOrNil(node.Left), valOrNil(node.Right))

	// Print current node
	fmt.Print(prefix)
	if isLast {
		fmt.Print("└── ")
	} else {
		fmt.Print("├── ")
	}
	fmt.Println(node.Val)

	// Update prefix for children
	if !isLast {
		prefix += "│   "
		hasNonLastAncestor = true
	} else {
		// For last child, always use spaces
		// The vertical line from non-last ancestors is already maintained in the prefix
		prefix += "    "
	}

	// Print children
	if node.Left != nil || node.Right != nil {
		if node.Left != nil {
			printTreeHelper(node.Left, prefix, node.Right == nil, hasNonLastAncestor)
		}
		if node.Right != nil {
			printTreeHelper(node.Right, prefix, true, hasNonLastAncestor)
		}
	}
}

func Lookup(arr []int, target int) int {
	for i, num := range arr {
		if num == target {
			return i
		}
	}
	return -1
}

// subTreeFrom recursively constructs a subtree rooted at the node with value 'rootVal'
// visitedPre and visitedPost track which nodes have been processed in each traversal
func subTreeFrom(preorder, postorder []int, rootVal int, visitedPre, visitedPost []bool) *TreeNode {
	n := len(preorder)
	preIndex := Lookup(preorder, rootVal)   // Find root in preorder
	postIndex := Lookup(postorder, rootVal) // Find root in postorder
	visitedPre[preIndex] = true             // Mark root as visited in preorder
	visitedPost[postIndex] = true           // Mark root as visited in postorder

	var leftNode, rightNode *TreeNode = nil, nil
	// Left child is the next unvisited element in preorder (after root)
	// Right child is the previous unvisited element in postorder (before root)
	leftIndex := preIndex + 1
	rightIndex := postIndex - 1

	// Check if left child exists (next element in preorder is unvisited)
	if leftIndex < n && !visitedPre[leftIndex] {
		leftVal := preorder[leftIndex]
		visitedPre[Lookup(preorder, leftVal)] = true
		visitedPost[Lookup(postorder, leftVal)] = true
	} else {
		leftIndex = -1 // No left child
	}

	// Check if right child exists (previous element in postorder is unvisited)
	if rightIndex >= 0 && !visitedPost[rightIndex] {
		rightVal := postorder[rightIndex]
		visitedPre[Lookup(preorder, rightVal)] = true
		visitedPost[Lookup(postorder, rightVal)] = true
	} else {
		rightIndex = -1 // No right child
	}

	// Recursively build left subtree
	if leftIndex != -1 {
		leftNode = subTreeFrom(preorder, postorder, preorder[leftIndex], visitedPre, visitedPost)
	}
	// Recursively build right subtree
	if rightIndex != -1 {
		rightNode = subTreeFrom(preorder, postorder, postorder[rightIndex], visitedPre, visitedPost)
	}

	return &TreeNode{
		Val:   rootVal,
		Left:  leftNode,
		Right: rightNode,
	}
}

// ConstructTree constructs a binary tree from preorder and postorder traversals
// The root is always preorder[0] (first element in preorder traversal)
func ConstructTree(preorder []int, postorder []int) *TreeNode {
	n := len(preorder)
	if n == 0 {
		return nil
	}

	// Start with root (first element in preorder) and initialize tracking arrays
	return subTreeFrom(preorder, postorder, preorder[0], make([]bool, n), make([]bool, n))
}
