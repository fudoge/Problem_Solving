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
    ListNode* swapNodes(ListNode* head, int k) {
        if (head == nullptr)
            return nullptr;

        ListNode* node1 = nullptr;
        ListNode* prev_node1 = nullptr;
        ListNode* node2 = nullptr;
        ListNode* prev_node2 = nullptr;
        ListNode* current = head;
        int count = 0;

        // Find the kth node from the beginning
        while (current != nullptr) {
            count++;
            if (count == k) {
                node1 = current;
                break;
            }
            prev_node1 = current;
            current = current->next;
        }

        ListNode* runner = node1;
        while (runner != nullptr) {
            prev_node2 = node2;
            node2 = (node2 == nullptr) ? head : node2->next;
            runner = runner->next;
        }

        if (node1 == nullptr || node2 == nullptr){
            return head;
        }

        if (prev_node1 != nullptr)
            prev_node1->next = node2;
        else
            head = node2;

        if (prev_node2 != nullptr)
            prev_node2->next = node1;
        else
            head = node1;

        ListNode* temp = node1->next;
        node1->next = node2->next;
        node2->next = temp;

        return head;
    }
};