/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func createBinaryTree(descriptions [][]int) *TreeNode {
    nodes := make([]*TreeNode, 100001)
    indegree := make([]int, 100001)
    isNodeExists := make(map[int]bool)
    
    for i := 0; i < 100001; i++ {
        nodes[i] = &TreeNode{
            Val: i,
            Left: nil,
            Right: nil,
        }
    }
    
    for _, desc := range descriptions {
        p := desc[0]
        c := desc[1]
        isLeft := desc[2]
        isNodeExists[p] = true
        isNodeExists[c] = true
        indegree[c]++
        
        if isLeft == 1 {
            nodes[p].Left = nodes[c]
        } else {
            nodes[p].Right = nodes[c]
        }
    }

    for k, _ := range isNodeExists {
        if indegree[k] == 0 {
            return nodes[k]
        }
    }
    return nil
}