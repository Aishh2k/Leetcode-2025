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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;

        while(count<k){
            if(temp == NULL){
                return head;
            }
            temp = temp->next;
            count++;
        }

        ListNode* prev = reverseKGroup(temp,k);

        count = 0;
        temp = head;
        while(count<k){
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
            count++;
        }
        return prev;
    }
};