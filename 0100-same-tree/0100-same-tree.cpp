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
    void traverse(TreeNode* root, string &s) {
        if(root == nullptr) {
            s += "n";
            return;
        }

        s += to_string(root -> val);
        traverse(root -> left, s);
        traverse(root -> right, s);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        string s1 = "";
        string s2 = "";

        traverse(p, s1);
        traverse(q, s2);

        return s1 == s2;
    }
};