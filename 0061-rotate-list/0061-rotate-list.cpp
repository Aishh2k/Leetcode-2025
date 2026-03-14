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

        if(!head){
            return head;
        }

        ListNode* temp = head;
        int count = 0;

        while(temp){
            temp = temp->next;
            count++; //3
        }

        k = k%count; 
        if(k ==0){
            return head;
        }

        ListNode* fast = head;
        for(int i =0;i<count-k-1;i++){
            fast = fast->next;
        }
        
        ListNode* newHead = fast->next;
        fast->next = NULL;
        temp = newHead;
        while(temp != NULL && temp->next != NULL){
            temp = temp->next;
        }
        temp->next = head;
        return (newHead);
        
    }
};