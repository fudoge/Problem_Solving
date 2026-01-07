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
using ll = long long;
class Solution {
public:
    ll MOD = 1e9+7;
    ll ans = 0;
    ll minDiff = LLONG_MAX;
    ll sum = 0;
    ll dfs1(TreeNode* root) {
        if(!root) return 0;
        return dfs1(root -> left) + dfs1(root -> right) + root -> val;
    }
    ll dfs2(TreeNode* root) {
        if(!root) return 0;
        ll subtreeSum = dfs2(root -> left) + dfs2(root -> right) + root -> val;
        ll rest = sum - subtreeSum;
        ll diff = abs(rest - subtreeSum);
        if(diff < minDiff) {
            minDiff = diff;
            ans = ((subtreeSum % MOD) * (rest % MOD))%MOD;
        }
        return subtreeSum;
    }
    int maxProduct(TreeNode* root) {
        sum = dfs1(root);

        dfs2(root);
        return ans;
    }
};