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
    void traverse(TreeNode* root, TreeNode* parent, bool isLeftChild, set<int>& to_delete, vector<TreeNode*>& forest) {
        if(!root) return;
        if(to_delete.find(root -> val) != to_delete.end()) {
            to_delete.erase(root -> val);
            if(isLeftChild) {
                parent -> left = NULL;
            } else {
                parent -> right = NULL;
            }
            auto leftChild = root -> left;
            auto rightChild = root -> right;
            root -> left = NULL;
            root -> right = NULL;
            traverse(leftChild, root, true, to_delete, forest);
            traverse(rightChild, root, false, to_delete, forest);
        } else {
            if((isLeftChild && parent -> left == NULL) || (!isLeftChild && parent -> right == NULL)) {
                forest.push_back(root);
            }
            traverse(root -> left, root, true, to_delete, forest);
            traverse(root -> right, root, false, to_delete, forest);
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> forest;
        set<int> to_delete_set(to_delete.begin(), to_delete.end());
        if(to_delete_set.find(root -> val) != to_delete_set.end()) {
            to_delete_set.erase(root -> val);
            auto leftChild = root -> left;
            auto rightChild = root -> right;
            root -> left = NULL;
            root -> right = NULL;
            traverse(leftChild, root, true, to_delete_set, forest);
            traverse(rightChild, root, false, to_delete_set, forest);
        } else {
            forest.push_back(root);
            traverse(root -> left, root, true, to_delete_set, forest);
            traverse(root -> right, root, false, to_delete_set, forest);
        }

        return forest;
    }
};