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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        auto left = list1;
        auto right = list1;

        for(int i = 0; i < b-a+1; i++) {
            right = right -> next;
        }

        for(int i = 0; i < a-1; i++) {
            right = right -> next;
            left = left -> next;
        }

        left -> next = list2;
        
        while(left -> next != NULL) {
            left = left -> next;
        }

        left -> next = right -> next;

        return list1;
    }
};