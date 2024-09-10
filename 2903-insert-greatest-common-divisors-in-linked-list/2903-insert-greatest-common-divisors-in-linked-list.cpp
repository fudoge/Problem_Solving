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
    int gcd(int a, int b) {
        if(a%b == 0) return b;
        return gcd(b, a%b);
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        auto left = head;
        auto right = head -> next;

        while(right != NULL) {
            ListNode* newNode = new ListNode(gcd(max(left -> val, right -> val), min(left -> val, right -> val)));

            left -> next = newNode;
            newNode -> next = right;
            left = right;
            right = right -> next;
        }

        return head;
    }
};