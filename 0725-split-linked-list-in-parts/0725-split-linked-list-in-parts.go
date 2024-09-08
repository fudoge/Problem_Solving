/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func splitListToParts(head *ListNode, k int) []*ListNode {
    n := 0
    curr := head

    for curr != nil {
        n++
        curr = curr.Next
    }

    rest := n % k
    div := n / k
    var prev *ListNode
    curr = head
    ans := make([]*ListNode, 0, k)

    for i := 0; i < rest; i++ {
        ans = append(ans, curr)
        for j := 0; j < div+1; j++ {
            prev = curr
            curr = curr.Next
        }
        prev.Next = nil
    }

    for curr != nil {
        ans = append(ans, curr)
        for j := 0; j < div; j++ {
            prev = curr
            curr = curr.Next
        }
        prev.Next = nil
    }

    for i := len(ans); i < k; i++ {
        ans = append(ans, nil)
    }

    return ans
}