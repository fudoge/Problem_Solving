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
    int count = 0;
public:
    pair<int, int> postOrder(TreeNode* rooot) {
        if(rooot == nullptr) return make_pair(0, 0);

        auto left = postOrder(rooot -> left);
        auto right = postOrder(rooot -> right);
        int sum = left.first + right.first + rooot -> val;
        int num = left.second + right.second + 1;
        if(sum / num == rooot -> val) {
            count++;
        }
        return make_pair(sum, num);
    }

    int averageOfSubtree(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        auto x = postOrder(root);

        return count;
    }
};