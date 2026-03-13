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

        ListNode* temp = head;
        stack<ListNode*> st;

        while(temp){
            st.push(temp);
            temp = temp->next;
        }
        temp = head;
        int n = st.size();
        ListNode* top;

        for(int i =0;i<n/2;i++){
            top = st.top();
            st.pop();
            ListNode* next = temp->next;
            temp->next = top;
            top->next = next;
            temp = next;
        }
        temp->next = NULL;
        
    }
};