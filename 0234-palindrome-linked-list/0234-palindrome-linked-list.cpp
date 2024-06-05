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
    bool isPalindrome(ListNode* head) {
        int n = 0;

        auto node = head;
        while(node != NULL) {
            n++;
            node = node -> next;
        }
        node = head;

        if(n == 1) return true;

        auto next = node;
        ListNode* prev = NULL;
        for(int i = 0; i < n/2; i++) {
            next = node -> next;
            node -> next = prev;
            prev = node;
            node = next;
        }

        if(n%2) {
            next = next -> next;
        }

        while(prev != NULL && next != NULL) {
            if(prev -> val != next -> val) return false;
            prev = prev -> next;
            next = next -> next;
        }

        return true;
    }
};