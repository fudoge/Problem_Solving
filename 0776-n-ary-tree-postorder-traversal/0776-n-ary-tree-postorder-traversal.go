/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */
func traverse(root *Node, ans *[]int) {
    if root == nil {
        return
    }
    for _, child := range root.Children {
        traverse(child, ans)
    }
    *ans = append(*ans, root.Val)
}

func postorder(root *Node) []int {
    var ans []int
    traverse(root, &ans)
    return ans
}