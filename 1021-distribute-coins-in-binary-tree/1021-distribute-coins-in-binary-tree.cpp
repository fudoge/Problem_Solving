/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
private:
    int ans;
public:
    int distributeCoins(TreeNode* root, TreeNode* parent = NULL) {
        if(!root) return 0;
        int m = distributeCoins(root -> left, root) + distributeCoins(root -> right, root);
        int x = root -> val - 1;
        if(parent) parent -> val += x;
        m += abs(x);

        return m;
    }
};