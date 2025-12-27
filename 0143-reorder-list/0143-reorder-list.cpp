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
    void reorderList(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = NULL;
        ListNode* cur = slow->next;
        ListNode* temp = slow->next;
        slow->next = NULL;

        while(cur){
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }

        slow = head;
        fast = prev;

        while(slow && fast){
            ListNode* next1 = slow->next;
            ListNode* next2 = fast->next;
        
            slow->next = fast;
            fast->next = next1;

            slow = next1;
            fast = next2;
        } 
        
    }
};