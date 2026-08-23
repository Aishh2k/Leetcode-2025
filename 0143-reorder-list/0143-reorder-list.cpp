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
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* prev = NULL;
        ListNode* temp = slow;
        ListNode* cur = slow->next;
        slow->next = NULL;

        while(cur){
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }

        temp = head;
        while(prev){
            ListNode* prevn = prev->next;
            ListNode* tempn = temp->next;
            temp->next = prev;
            prev->next = tempn;
            prev = prevn;
            temp = tempn;
        }
        
    }
};