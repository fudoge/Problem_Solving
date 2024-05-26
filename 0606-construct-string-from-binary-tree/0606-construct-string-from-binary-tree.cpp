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

 static const int __ = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
 }();

class Solution {
public:
    string prefix_traversal(TreeNode* root) {
        if(root == nullptr) return "";
        string left = "";
        string right = "";
        if(root -> left || root -> right) {
            left = "(" + prefix_traversal(root -> left) + ")";
        }
        if(root -> right) {
            right = "(" + prefix_traversal(root -> right) + ")";
        }
        return to_string(root -> val) + left + right;
    }
    string tree2str(TreeNode* root) {
        return prefix_traversal(root);
    }
};