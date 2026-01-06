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
#pragma GCC optimize("O3", "unroll-loops");
static const int __ = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = -1;
        int it = 1;
        int maxSum = INT_MIN;
        while(!q.empty())  {
            int qs = q.size();
            int sum = 0;
            for(int i = 0; i < qs; i++) {
                auto curr = q.front();
                q.pop();
                sum += curr -> val;
                if(curr -> left) q.push(curr -> left);
                if(curr -> right) q.push(curr -> right);
            }
            if(sum > maxSum) {
                ans = it;
                maxSum = sum;
            }
            it++;
        }
        return ans;
    }
};