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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        auto left = head;
        auto mid = left -> next;
        auto right = mid -> next;

        int minimumDistance = INT_MAX;
        int maximumDistance = -1;
        int idx = 1;
        int lastCritical = 0;
        int firstCritical = 0;
        if(mid == NULL || right == NULL) return {-1, -1};

        while(firstCritical == 0 && right != NULL) {
            // islocalMaxima
            if(mid -> val > left -> val && mid -> val > right -> val) {
                firstCritical = idx;
                lastCritical = idx;
            }
            // islocalMinima
            else if(mid -> val < left -> val && mid -> val < right -> val) {
                firstCritical = idx;
                lastCritical = idx;
            }
            left = left -> next;
            mid = mid -> next;
            right = right -> next;
            idx++;
        }
        if(firstCritical == 0) return {-1, -1};
        while(right != NULL) {
            // islocalMaxima
            if(mid -> val > left -> val && mid -> val > right -> val) {
                minimumDistance = min(minimumDistance, idx - lastCritical);
                lastCritical = idx;
                maximumDistance = lastCritical - firstCritical;
            }
            // islocalMinima
            else if(mid -> val < left -> val && mid -> val < right -> val) {
                minimumDistance = min(minimumDistance, idx - lastCritical);
                lastCritical = idx;
                maximumDistance = lastCritical - firstCritical;
            }
            left = left -> next;
            mid = mid -> next;
            right = right -> next;
            idx++;
        }
        if(firstCritical == lastCritical) return {-1, -1};
        
        return {minimumDistance, maximumDistance};
    }
};