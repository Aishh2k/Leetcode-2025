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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = NULL;
        fast = slow;

        while(slow){
            fast = slow->next;
            slow->next = prev;
            prev = slow;
            slow = fast;
        }
        // prev
        fast = head;

        int sum = 0;

        while(prev && fast){
            sum = max(sum, prev->val + fast->val);
            prev = prev->next;
            fast = fast->next;
        }
        return sum;
    }
};