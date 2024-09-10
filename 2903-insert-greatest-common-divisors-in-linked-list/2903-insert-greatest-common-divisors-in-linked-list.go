/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func gcd(a, b int) int {
    if b == 0 {
        return a
    }
    return gcd(b, a % b)
}

func insertGreatestCommonDivisors(head *ListNode) *ListNode {

    current := head
    for current.Next != nil {
        g := gcd(current.Val, current.Next.Val)

        newNode := &ListNode{Val: g}
        newNode.Next = current.Next
        current.Next = newNode
        current = newNode.Next
    }

    return head
}