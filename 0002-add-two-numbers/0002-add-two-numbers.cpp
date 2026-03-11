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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int a, b, sum;
        ListNode* head = nullptr;
        ListNode* temp = nullptr;

        while(l1 || l2 || carry){
            a = l1? l1->val:0;
            b = l2? l2->val:0;
            sum = a+b+carry;
            carry = sum/10;
            sum = sum%10;
            ListNode* node  = new ListNode(sum);
            if(!head){
                head = node;
                temp = node;
            }else{
                temp->next = node;
                temp = node;
            }

            if(l1){
                l1 = l1->next;
            }
            if(l2){
                l2 = l2->next;
            }
        }
        return head;
    }
};