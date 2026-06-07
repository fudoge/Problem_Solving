/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func createBinaryTree(descriptions [][]int) *TreeNode {
    nodes := make(map[int]*TreeNode)
    root := 0 
    
    for _, desc := range descriptions {
        p := desc[0]
        c := desc[1]
        isLeft := desc[2]

        if _, exists := nodes[p]; !exists {
            nodes[p] = &TreeNode {
                Val: p,
            }
            root += p
        }
        if _, exists := nodes[c]; !exists {
            nodes[c] = &TreeNode {
                Val: c,
            }
            root += c
        }

        if isLeft == 1 { 
            nodes[p].Left = nodes[c] 
        } else { 
            nodes[p].Right = nodes[c] 
        }
        root -= c
    }
    return nodes[root]
}