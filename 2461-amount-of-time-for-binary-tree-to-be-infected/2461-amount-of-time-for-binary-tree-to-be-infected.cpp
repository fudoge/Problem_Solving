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

static const int __ = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    void traverse(TreeNode* root, unordered_map<int, vector<int>>& mp) {
        if(root -> left) {
            mp[root -> val].push_back(root -> left -> val);
            mp[root -> left -> val].push_back(root -> val);
            traverse(root -> left, mp);
        } 
        if(root -> right) {
            mp[root -> val].push_back(root -> right -> val);
            mp[root -> right -> val].push_back(root -> val);
            traverse(root -> right, mp);
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> mp;
        unordered_map<int, bool> visited;
        traverse(root, mp);

        queue<int> q;
        q.push(start);
        visited[start] = true;
        int time = -1;

        while(!q.empty()) {
            int qSize = q.size();

            for(int i = 0; i < qSize; i++) {
                int curr = q.front();
                q.pop();

                for(const auto &next : mp[curr]) {
                    if(!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    } 
                }
            }
            time++;
        }

        return time;
    }
};