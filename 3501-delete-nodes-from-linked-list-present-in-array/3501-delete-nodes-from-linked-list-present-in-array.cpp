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
        unordered_set<int> s(nums.begin(), nums.end());
        auto dummy = ListNode(0, head);
        auto curr = head;
        auto prev = &dummy;

        while (curr != nullptr) {
            if (s.find(curr->val) != s.end()) {
                prev->next = curr->next;
            } else {
                prev = prev->next;
            }

            curr = curr->next;
        }

        return dummy.next;
    }
};