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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode();
        dummy->next = head;

        ListNode* curNode = dummy->next;
        ListNode* leftHead = dummy;

        for(int i =0;i<left-1;i++){
            curNode = curNode->next;
            leftHead = leftHead->next;
        }
        ListNode* savedCur = curNode;
        ListNode* temp;
        ListNode* prev = NULL;

        for(int i =0;i<right-left+1;i++){
            temp = curNode->next;
            curNode->next = prev;
            prev = curNode;
            curNode = temp;
        }
        leftHead->next = prev;
        savedCur->next = curNode;

        return dummy->next;
        
        
    }
};