/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func spiralMatrix(m int, n int, head *ListNode) [][]int {
    ans := make([][]int, m)
    for i := range ans {
        ans[i] = make([]int, n)
        for j := range ans[i] {
            ans[i][j] = -1
        }
    }

    rowStart := 0
    rowEnd := m - 1
    colStart := 0
    colEnd := n - 1

    for head != nil {
        for col := colStart; col <= colEnd && head != nil; col++ {
            ans[rowStart][col] = head.Val
            head = head.Next
        }
        rowStart++

        for row := rowStart; row <= rowEnd && head != nil; row++ {
            ans[row][colEnd] = head.Val
            head = head.Next
        }
        colEnd--

        for col := colEnd; col >= colStart && head != nil; col-- {
            ans[rowEnd][col] = head.Val
            head = head.Next
        }
        rowEnd--

        for row := rowEnd; row >= rowStart && head != nil; row-- {
            ans[row][colStart] = head.Val
            head = head.Next
        }
        colStart++
    }

    return ans
}