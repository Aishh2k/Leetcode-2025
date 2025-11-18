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
    ListNode* removeElements(ListNode* head, int val) {
        if( head == NULL){
            return head;
        }
        ListNode* cur;

        while(head!= NULL && head->val == val ){
            cur = head;
            head = head->next;
            delete cur;
        }

        ListNode* temp;
        temp = head;

        while(temp!= NULL){
            if(temp->val!= val){
                cur = temp;
                temp = temp->next;
            }else{
                cur->next = temp->next;
                temp->next = NULL;
                temp = cur->next;

            }
        }

        return head;
        
    }
};