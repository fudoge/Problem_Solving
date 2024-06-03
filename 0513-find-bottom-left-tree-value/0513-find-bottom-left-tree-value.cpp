/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int, int> traverse(TreeNode* node, int depth) {
        if(node == nullptr) return {-1, 0};
        if(!(node -> left) && !(node -> right)) return {depth, node -> val};
        auto left = traverse(node -> left, depth+1);
        auto right = traverse(node -> right, depth+1);

        if(left.first >= right.first) return left;
        return right;
    }

    int findBottomLeftValue(TreeNode* root) {
        auto it = traverse(root, 1);
        return it.second;
    }
};