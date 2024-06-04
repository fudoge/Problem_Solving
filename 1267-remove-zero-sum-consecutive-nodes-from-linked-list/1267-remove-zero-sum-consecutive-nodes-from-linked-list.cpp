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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if (head == NULL) return head;

        auto curr = head;
        int sum = 0;

        while(curr != NULL) {
            sum += curr -> val;
            if(sum == 0) {
                head = curr -> next;
                return removeZeroSumSublists(head);
            }

            curr = curr -> next;
        }

        head -> next = removeZeroSumSublists(head -> next);
        return head;
    }
};