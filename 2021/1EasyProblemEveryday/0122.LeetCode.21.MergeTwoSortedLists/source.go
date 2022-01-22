package leetcode

type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
	if list1 == nil {
		return list2
	}
	if list2 == nil {
		return list1
	}

	merge := func(a, b *ListNode) *ListNode {
		a.Next = mergeTwoLists(a.Next, b)
		return a
	}

	if list1.Val <= list2.Val {
		return merge(list1, list2)
	} else {
		return merge(list2, list1)
	}
}
