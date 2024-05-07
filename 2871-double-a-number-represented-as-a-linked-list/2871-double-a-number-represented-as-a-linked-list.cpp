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
    int carry = 0;
public:
    void solve(ListNode* node) {
        if(node->next == nullptr) {
            int x = (node->val * 2) + carry;
            node->val = x % 10;
            carry = x / 10;
            return;
        }
        solve(node->next);
        int x = node->val * 2 + carry;
        carry = x / 10;
        node->val = x % 10;
    }
    ListNode* doubleIt(ListNode* head) {
        solve(head);
        if(carry > 0) {
            ListNode* newNode = new ListNode(carry);
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
};
