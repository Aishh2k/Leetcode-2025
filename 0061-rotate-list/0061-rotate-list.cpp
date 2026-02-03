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
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 1;
        ListNode* tail = head;

        if(!head || k==0){
            return head;
        }

        while (tail->next) {
            n++;
            tail = tail->next;
        }

        k %= n;
        if (k == 0) {
            return head;
        }

        tail->next = head;
        int step = n - k;

        while (step) {
            tail = tail->next;
            step--;
        }
        ListNode* newHead = tail->next;
        tail->next = NULL;

        return (newHead);
    }
};