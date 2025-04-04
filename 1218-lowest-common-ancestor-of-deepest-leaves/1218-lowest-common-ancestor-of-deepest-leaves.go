/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func isLeaf(root *TreeNode) bool {
	return root.Left == nil && root.Right == nil
}

func solve(root *TreeNode, depth int) (*TreeNode, int) {
	if root == nil {
		return nil, -1
	}
	if isLeaf(root) {
		return root, depth
	}

	l, ld := solve(root.Left, depth+1)
	r, rd := solve(root.Right, depth+1)

	if ld > rd {
		return l, ld
	} else if ld < rd {
		return r, rd
	} else {
		return root, ld
	}
}

func lcaDeepestLeaves(root *TreeNode) *TreeNode {
	ans, _ := solve(root, 0)
	return ans
}
