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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head){
            return head;
        }

        ListNode* temp = head;
        int len = 1;

        while(temp->next){
            len++;
            temp = temp->next;
        }

        if(len == n){
            return head->next;
        }

        temp = head;

        for(int i =0 ;i<len-n-1;i++){
            temp = temp->next;
        }

        temp->next = temp->next->next;
        return head;
        
    }
};