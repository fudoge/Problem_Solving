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
private:
    TreeNode* ans;
    int maxDepth;
public:
    int dfs(TreeNode* root, int depth) {
        if(!root) return depth;
        if(!(root->left) && !(root->right)) {
            if(depth >= maxDepth) {
                maxDepth = depth;
                ans = root;
            }
            return depth;
        }
        int l = 0;
        if(root->left) l = dfs(root->left, depth+1);
        int r = 0;
        if(root -> right) r = dfs(root->right, depth+1);
        int d = max({l, r, depth});
        if(l != 0 && r != 0 && l == r) {
            if(d >= maxDepth) {
                ans = root;
                maxDepth = d;
            }
        }
        return d;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        dfs(root, 1);
        return ans;
    }
};