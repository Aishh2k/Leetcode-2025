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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* newHead = NULL;
        ListNode* first = head;
        ListNode* second;
        ListNode* next;
        ListNode* prev = NULL;

        while (first && first->next) {
            next = first->next->next;
            second = first->next;

            first->next = next;
            second->next = first;

            if (!newHead) {
                newHead = second;
            }

            if (prev) {
                prev->next = second;
            }

            prev = first;
            first = next;
        }

        return newHead;
    }
};