/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func modifiedList(nums []int, head *ListNode) *ListNode {
    m := make(map[int]bool)
    for _, v := range nums {
        m[v] = true
    }

    for head != nil && m[head.Val] {
        head = head.Next
    }

    if head == nil {
        return nil
    }

    curr := head
    for curr != nil && curr.Next != nil {
        if m[curr.Next.Val] {
            curr.Next = curr.Next.Next
        } else {
            curr = curr.Next
        }
    }

    if curr != nil {
        curr.Next = nil
    }

    return head
}