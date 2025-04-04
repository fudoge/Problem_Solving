/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   public:
    bool isLeaf(TreeNode *root) { return !root->left && !root->right; }

    pair<TreeNode *, int> solve(TreeNode *root, int depth) {
        if (!root) return {nullptr, 0};
        if (isLeaf(root)) return {root, depth};

        auto l = solve(root->left, depth + 1);
        auto r = solve(root->right, depth + 1);

        if (l.second > r.second) {
            return l;
        } else if (l.second < r.second) {
            return r;
        } else {
            return {root, l.second};
        }
    }
    TreeNode *lcaDeepestLeaves(TreeNode *root) { return solve(root, 0).first; }
};