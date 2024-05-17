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
    int target;
public:
    void solve(TreeNode* root) {
        if(root -> left) {
            solve(root -> left);
            if(root -> left -> val == target && !(root -> left -> left) && !(root -> left -> right)) {
                root -> left = NULL;
            }
        }
        if(root -> right) {
            solve(root -> right);
            if(root -> right -> val == target && !(root -> right -> left) && !(root -> right -> right)) {
                root -> right = NULL;
            }
        }
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        this -> target = target;
        solve(root);
        if(root -> val == target && !(root -> right) && !(root -> left)) return NULL;
        return root;
    }
};