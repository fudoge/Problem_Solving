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

static const auto __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    void traverse(TreeNode* root, vector<int> &seq) {
        if(!root -> left && !root -> right) {
            seq.push_back(root -> val);
            return;
        }

        if(root -> left) {
            traverse(root -> left, seq);
        }
        if(root -> right) {
            traverse(root -> right, seq);
        }
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> seq1, seq2;
        traverse(root1, seq1);
        traverse(root2, seq2);

        if(seq1.size() != seq2.size()) return false;
        for(int i = 0; i < seq1.size(); i++) {
            if(seq1[i] != seq2[i]) return false;
        }
        return true;
    }
};