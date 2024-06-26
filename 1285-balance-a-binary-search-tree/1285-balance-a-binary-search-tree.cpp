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
    vector<int> arr;
public:
    void inorder(TreeNode* root) {
        if(root == NULL) return;
        inorder(root -> left);
        arr.push_back(root -> val);
        inorder(root -> right);
    }

    TreeNode* generate(int left, int right) {
        if(left > right) return NULL;
        int mid = (left + right)/2;
        TreeNode* leftNode = (left > mid-1)? NULL:generate(left, mid-1);
        TreeNode* rightNode = (mid+1 > right)? NULL:generate(mid+1, right);
        return new TreeNode(arr[mid], leftNode, rightNode);
    }

    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return generate(0, arr.size()-1);
    }
};