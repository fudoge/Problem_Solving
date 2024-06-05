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
private:
    ListNode* head;
public:
    void reverse(ListNode* curr, ListNode *prev) {
        if(curr == NULL) {
            this -> head = prev;
            return;
        }
        reverse(curr -> next, curr);
        curr -> next = prev;
    }

    ListNode* reverseList(ListNode* head) {
        reverse(head, NULL);
        return this -> head;
    }
};