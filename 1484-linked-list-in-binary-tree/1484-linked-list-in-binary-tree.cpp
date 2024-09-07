#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();


class Solution {
public:
    bool checkPath(ListNode* head, TreeNode* root) {
        if (!head) return true;
        if (!root) return false;
        
        if (root->val == head->val) {
            return checkPath(head->next, root->left) || checkPath(head->next, root->right);
        }
        return false;
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;
        
        return checkPath(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};