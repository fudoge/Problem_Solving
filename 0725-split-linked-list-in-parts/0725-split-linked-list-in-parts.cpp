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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        auto curr = head;
        while(curr != NULL) {
            n++;
            curr = curr -> next;
        }

        vector<ListNode*> ans;
        int rest = n % k;
        int div = n / k;

        curr = head;
        ListNode* prev;
        for(int i = 0; i < rest; i++) {
            ans.push_back(curr);
            for(int j = 0; j < div+1; j++) {
                prev = curr;
                curr = curr -> next;
            }
            prev -> next = NULL;
        }

        while(curr != NULL) {
            ans.push_back(curr);
            for(int j = 0; j < div; j++) {
                prev = curr;
                curr = curr -> next;
            }
            prev -> next = NULL;
        }

        for(int i = ans.size(); i < k; i++) {
            ans.push_back(NULL);
        }

        return ans;
    }
};