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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> sums;

        q.push(root);
        while(!q.empty()) {
            int sum = 0;
            int qSize = q.size();
            for(int i = 0; i < qSize; ++i) {
                auto curr = q.front();
                q.pop();
                sum += curr -> val;
                if(curr -> left) q.push(curr -> left);
                if(curr -> right) q.push(curr -> right);
            }
            sums.push_back(sum);
        }

        q.push(root);
        int level = 0;
        while(!q.empty()) {
            int qSize = q.size();
            for(int i = 0; i < qSize; ++i) {
                auto curr = q.front();
                q.pop();

                int childrenSum = 0;
                childrenSum += curr -> left? curr -> left -> val : 0;
                childrenSum += curr -> right? curr -> right -> val : 0;

                if(curr -> left) {
                    curr -> left -> val = sums[level+1] - childrenSum;
                    q.push(curr -> left);
                }
                if(curr -> right) {
                    curr -> right -> val = sums[level+1] - childrenSum;
                    q.push(curr -> right);
                }
            }
            level++;
        }

        root -> val = 0;
        return root;
    }
};