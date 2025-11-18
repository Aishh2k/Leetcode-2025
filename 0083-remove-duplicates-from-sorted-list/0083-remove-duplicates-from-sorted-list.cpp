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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp;
        ListNode* cur;
        temp = head;
        cur = head;
        unordered_set<int> s;

        while(temp!= NULL){
            if(!s.count(temp->val)){
                s.insert(temp->val);
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