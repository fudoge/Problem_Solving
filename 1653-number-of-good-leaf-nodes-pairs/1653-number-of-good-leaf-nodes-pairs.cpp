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
    int pairs;
public:
    vector<int> traverse(TreeNode* root, int distance) {
        if(!root) return {};
        if(!(root -> left) && !(root -> right)) return {1};
        vector<int> leftLeaves = traverse(root -> left, distance);
        vector<int> rightLeaves = traverse(root -> right, distance);

        for(const auto &leftLeaf : leftLeaves) {
            for(const auto & rightLeaf : rightLeaves) {
                if(leftLeaf + rightLeaf <= distance) pairs++;
            }
        }

        vector<int> leaves;
        for(const auto &leftLeaf : leftLeaves) {
            if(leftLeaf+1 >= distance) continue;
            leaves.push_back(leftLeaf+1);
        }
        for(const auto &rightLeaf : rightLeaves) {
            if(rightLeaf+1 >= distance) continue;
            leaves.push_back(rightLeaf+1);
        }

        return leaves;
    }
    int countPairs(TreeNode* root, int distance) {
        pairs = 0;
        traverse(root, distance);
        return pairs;
    }
};