/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func modifiedList(nums []int, head *ListNode) *ListNode {
	mp := make(map[int]bool)
	for _, num := range nums {
		mp[num] = true
	}

	dummy := &ListNode{Next: head}
	curr := head
	prev := dummy

	for curr != nil {
		if mp[curr.Val] {
			prev.Next = curr.Next
		} else {
			prev = curr
		}
		curr = prev.Next
	}

	return dummy.Next

}
