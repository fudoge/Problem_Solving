// Definition for a Node.
/*
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
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
    void traverse(Node* root, vector<int>& ans) {
        if(!root) return;
        for(const auto &child : root -> children) {
            traverse(child, ans);
        }
        ans.push_back(root -> val);
    }
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        traverse(root, ans);
        return ans;
    }
};