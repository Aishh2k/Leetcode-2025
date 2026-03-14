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

        if(!head){
            return head;
        }

        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp){
            if(temp->val != val){
                prev = temp;
                temp = temp->next;
            }else{
                if(temp == head){
                    head = head->next;
                    temp->next = NULL;
                    temp = head;
                }else{
                    ListNode* next = temp->next;
                    prev->next = next;
                    temp->next = NULL;
                    temp = next;
                }
            }
        }

        return head;
        
    }
};