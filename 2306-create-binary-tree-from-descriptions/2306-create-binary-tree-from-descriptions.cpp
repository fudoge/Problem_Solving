#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> children;
        
        for(const auto &description : descriptions) {
            int parentNum = description[0];
            int childNum = description[1];
            int isLeft = description[2];

            if(mp.find(childNum) == mp.end()) {
                mp[childNum] = new TreeNode(childNum);
            }

            if(mp.find(parentNum) == mp.end()) {
                mp[parentNum] = new TreeNode(parentNum);
            }

            if(isLeft) {
                mp[parentNum]->left = mp[childNum];
            } else {
                mp[parentNum]->right = mp[childNum];
            }

            children.insert(childNum);
        }

        TreeNode* root;;
        for(const auto &description : descriptions) {
            int parentNum = description[0];
            if(children.find(parentNum) == children.end()) {
                root = mp[parentNum];
                break;
            }
        }

        return root;
    }
};