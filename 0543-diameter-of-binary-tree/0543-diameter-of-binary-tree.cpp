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
    int diameter;
public:
    int traverse(TreeNode* node) {
        if(node == nullptr) return 0;
        if(!(node -> left) && !(node -> right)) return 1;
        int left = traverse(node -> left);
        int right = traverse(node -> right);
        diameter = max(diameter, left + right);

        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        traverse(root);
        return diameter;
    }
};