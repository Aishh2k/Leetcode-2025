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
    ListNode* partition(ListNode* head, int x) {

        ListNode* temp = head;
        ListNode* A = NULL;
        ListNode* B = NULL;

        ListNode* headA = NULL;
        ListNode* headB = NULL;

        while (temp != NULL) {
            if (temp->val < x) {
                if (!A) {
                    headA = temp;
                    A = temp;
                } else {
                    A->next = temp;
                    A = A->next;
                }
            } else {
                if (!B) {
                    headB = temp;
                    B = temp;
                } else {
                    B->next = temp;
                    B = B->next;
                }
            }
            temp = temp->next;
        }

        if (headB) {
            B->next = NULL;
        }

        if (headA) {
            A->next = headB;
            return headA;
        }

        return headB;
    }
};