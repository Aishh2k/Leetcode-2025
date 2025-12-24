/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

        ListNode* tempA = headA;
        ListNode* tempB = headB;

        int A = 0;
        int B = 0;

        while (tempA) {
            tempA = tempA->next;
            A++;
        }
        while (tempB) {
            tempB = tempB->next;
            B++;
        }

        int d = abs(A - B);
        int count = 0;
        tempA = headA;
        tempB = headB;

        if (A > B) {
            while (count < d) {
                tempA = tempA->next;
                count++;
            }
        } else {
            while (count < d) {
                tempB = tempB->next;
                count++;
            }
        }

        while (tempA && tempB) {
            if (tempA == tempB) {
                return tempA;
            }
            tempA = tempA->next;
            tempB = tempB->next;
        }

        return nullptr;
    }
};