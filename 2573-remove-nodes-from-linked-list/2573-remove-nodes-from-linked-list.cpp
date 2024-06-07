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

#pragma GCC optimize("03", "unroll-loops");

static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if(head == NULL) return NULL;
        head -> next = removeNodes(head -> next);
        if(head -> next == NULL) return head;
        if(head -> next -> val > head -> val) {
            return head -> next;
        }
        return head;
    }
};