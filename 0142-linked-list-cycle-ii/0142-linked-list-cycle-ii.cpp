/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        // unordered_set<ListNode*> st;

        // ListNode* temp = head;

        // while(temp){
        //     if(st.count(temp)){
        //         return temp;
        //     }
        //     st.insert(temp);
        //     temp = temp->next;
        // }

        // return nullptr;


        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                temp = head;
                while(temp != slow){
                    temp = temp->next;
                    slow = slow->next;
                }
                return slow;
            }
        }

        return nullptr;

        
        
    }
};