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
    TreeNode* findCommonAncestor(TreeNode* root, int a, int b) {
        if(!root || root -> val == a || root -> val == b) return root;

        auto left = findCommonAncestor(root -> left, a, b);
        auto right = findCommonAncestor(root -> right, a, b);
        if(left && right) {
            return root;
        }
        return left? left : right;
    }

    bool getRoute(TreeNode* root, int target, string &route) {
        if(!root) return false;
        if(root -> val == target) return true;

        route.push_back('L');
        if(getRoute(root -> left, target, route)) return true;
        route.pop_back();

        route.push_back('R');
        if(getRoute(root -> right, target, route)) return true;
        route.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string srcToRoot;
        string rootToDst;
        auto CA = findCommonAncestor(root, startValue, destValue);
        getRoute(CA, startValue, srcToRoot);
        getRoute(CA, destValue, rootToDst);

        for(int i = 0; i < srcToRoot.size(); i++) {
            srcToRoot[i] = 'U';
        }
        return srcToRoot + rootToDst;
    }
};