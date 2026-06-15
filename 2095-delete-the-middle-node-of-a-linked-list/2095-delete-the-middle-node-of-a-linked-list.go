/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteMiddle(head *ListNode) *ListNode {
    if head.Next == nil {
        return nil
    }
    midPrev := head
    mid := head
    end := head    

    for end != nil && end.Next != nil {
        midPrev = mid
        mid = mid.Next
        end = end.Next.Next
    }

    midPrev.Next = mid.Next
    mid.Next = nil

    return head
}