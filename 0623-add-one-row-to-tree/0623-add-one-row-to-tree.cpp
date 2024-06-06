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
#pragma GCC optimize("03", "unroll-loops");

static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
class Solution {
private:
    int val;
public:
    void solve(TreeNode* root, int depth) {
        if(depth == 1) {
            TreeNode* newLeft = new TreeNode(val, root -> left, NULL);
            root -> left = newLeft;

            TreeNode* newRight = new TreeNode(val, NULL, root -> right);
            root -> right = newRight;
        }

        if(root -> left) {
            solve(root -> left, depth-1);
        }

        if(root -> right) {
            solve(root -> right, depth-1);
        }
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        this -> val = val;
        if(depth == 1) {
            TreeNode* newNode = new TreeNode(val, root, NULL);
            return newNode;
        }
        solve(root, depth-1);
        return root;
    }
};