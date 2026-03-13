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
        // brute force

        // ListNode* temp = head;
        // stack<ListNode*> st;

        // while(temp){
        //     st.push(temp);
        //     temp = temp->next;
        // }
        // temp = head;
        // int n = st.size();
        // ListNode* top;

        // for(int i =0;i<n/2;i++){
        //     top = st.top();
        //     st.pop();
        //     ListNode* next = temp->next;
        //     temp->next = top;
        //     top->next = next;
        //     temp = next;
        // }
        // temp->next = NULL;


        // optimised

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* temp = slow->next; // reverse
        slow->next = NULL;
        ListNode* prev = NULL;
        ListNode* cur = temp;

        while(cur){
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }

        temp = head;
        //prev has head of revered list
        ListNode* next1;
        ListNode* next2;

        while(temp && prev){
            next1 = temp->next;
            next2 = prev->next;

            temp->next = prev;
            prev->next = next1;

            temp = next1;
            prev = next2;
        }

    }
};