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

        ListNode* temp = head;
        int count = 0;

        while(temp!= NULL){
            count++;
            temp = temp->next;
        }

        if(count == n){
            return head->next;
        }

        // count = 5
        // n = 2

        temp = head;
        ListNode* prev = head;

        for(int i =0;i<count-n;i++){ //0 1 2 
            prev = temp; //3
            temp = temp->next; //4
        }

        prev->next = temp->next;
        temp->next = NULL;
        return head;
        
    }
};