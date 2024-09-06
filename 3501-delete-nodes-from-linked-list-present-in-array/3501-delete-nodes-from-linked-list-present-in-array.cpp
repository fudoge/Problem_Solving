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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        auto curr = head;
        set<int> s(nums.begin(), nums.end());
        ListNode* newHead = NULL;
        ListNode* newTail = NULL;

        while(curr != NULL) {
            if(s.find(curr -> val) == s.end()) {
                if(!newHead) {
                    newHead = curr;
                    newTail = curr;
                } else {
                    newTail -> next = curr;
                    newTail = newTail -> next;
                }
            }
            curr = curr -> next;
        }

        if(newTail != NULL) {
            newTail -> next = NULL;
        }

        return newHead;
    }
};