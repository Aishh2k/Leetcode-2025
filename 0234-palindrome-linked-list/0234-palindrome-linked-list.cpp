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
    bool isPalindrome(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = NULL;
        ListNode* temp = slow;

        while(slow){
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }

        //prev is head of reversed
        temp = head;

        while(prev){
            if(temp->val != prev->val){
                return false;
            }
            temp = temp->next;
            prev = prev->next;
        }
        return true;



        
    }
};