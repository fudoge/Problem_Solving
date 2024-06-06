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
    int getSum(string trace, TreeNode* root) {

        if(root -> left == NULL && root -> right == NULL) {
            return stoi(trace);
        }

        int left = 0;
        if(root -> left != NULL) {
            left = getSum(trace + to_string(root -> left -> val), root -> left);
        }

        int right = 0;
        if(root -> right != NULL) {
            right = getSum(trace + to_string(root -> right -> val), root -> right);
        }

        return left + right;
    }

    int sumNumbers(TreeNode* root) {
        return getSum(to_string(root -> val), root);
    }
};