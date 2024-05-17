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
    int pairSum(ListNode* head) {
        int sum = 0;
        vector<int> node_val;
        ListNode* current = head;

        while(current != nullptr){
            node_val.push_back(current -> val);
            current = current -> next;
        }

        int n = node_val.size();

        for(int i = 0; i < n/2; i++){
            sum = max(sum, node_val[i] + node_val[n-1-i]);
        }

        return sum;
    }
};