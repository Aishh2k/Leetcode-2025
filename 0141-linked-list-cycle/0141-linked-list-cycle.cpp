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
    bool hasCycle(ListNode *head) {
        if(!head || !head->next){
            return false;
        }
        //ListNode* temp = head;
        // unordered_set<ListNode*> st;
        // while(temp){
        //     if(st.count(temp)){
        //         return true;
        //     }
        //     st.insert(temp);
        //     temp = temp->next;
        // }
        // return false;



        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(fast == slow){
                return true;
            }
        }

        return false;
        
    }
};