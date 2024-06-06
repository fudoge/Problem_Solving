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
    string solve(TreeNode* root, string str) {
        if(root -> left == NULL && root -> right == NULL) {
            reverse(str.begin(), str.end());
            return str;
        }

        string left = "";
        string right = "";

        if(root -> left) {
            char leftch = root -> left -> val + 'a';
            left = solve(root -> left, str + leftch);
        }
        
        if(root -> right) {
            char rightch = root -> right -> val + 'a';
            right = solve(root -> right, str + rightch);
        }

        if(left == "") return right;
        else if(right == "") return left;

        if(left < right) return left;
        return right;
    }
    string smallestFromLeaf(TreeNode* root) {
        char ch = 'a' + root -> val;
        string str = "";
        return solve(root, str + ch);
    }
};