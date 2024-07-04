#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        auto left = head;
        auto right = head -> next;

        while(right != NULL) {
            if(right -> val == 0) {
                left = left -> next;
                int val = 0;
                auto node = left;
                while(node != right) {
                    val += node -> val;
                    auto prev = node;
                    node = node -> next;
                    prev -> next = NULL;
                }
                left -> val = val;
                left -> next = right;
            }
            right = right -> next;
        }
        left -> next = NULL;
        return head -> next;
    }
};