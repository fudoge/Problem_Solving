/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

func postorder(root *Node) []int {
    if root == nil {
        return nil
    }
    
    var stack []*Node
    var ans []int

    stack = append(stack, root)
    for len(stack) > 0 {
        curr := stack[len(stack)-1]
        stack = stack[:len(stack)-1]
        
        ans = append(ans, curr.Val)
        
        for _, child := range curr.Children {
            stack = append(stack, child)
        }
    }
    
    for i, j := 0, len(ans)-1; i < j; i, j = i+1, j-1 {
        ans[i], ans[j] = ans[j], ans[i]
    }
    
    return ans
}