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
    vector<int> largestValues(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<int> largestVals;
        queue<TreeNode*> q;
        if(root == nullptr) return {};

        q.push(root);

        while(!q.empty()) {
            int repeat = q.size();
            int maxVal = INT_MIN;
            for(int i = 0; i < repeat; i++) {
                auto curr = q.front();
                q.pop();
                maxVal = max(maxVal, curr -> val);
                if(curr -> left != nullptr) {
                    q.push(curr -> left);
                }

                if(curr -> right != nullptr) {
                    q.push(curr -> right);
                }
            }

            largestVals.push_back(maxVal);
            
        }
        
        return largestVals;
    }
};