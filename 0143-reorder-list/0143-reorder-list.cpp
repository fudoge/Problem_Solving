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
    void reorderList(ListNode* head) {
        stack<ListNode*> s;
        int n = 0;

        auto node = head;
        while(node != NULL) {
            n++;
            node = node -> next;
        }

        if(n < 3) return;

        node = head;
        for(int i = 0; i < n/2 + (n%2); i++) {
            node = node -> next;
        }

        while(node != NULL) {
            s.push(node);
            node = node -> next;
        }

        node = head -> next;
        auto prev = head;

        while(!s.empty()) {
            prev -> next = s.top();
            s.top() -> next = node;
            s.pop();
            prev = node;
            node = node -> next;
        }

        if(n%2) {
            node = node -> next;
        }

        node -> next = NULL;
    }
};