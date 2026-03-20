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
    ListNode* mergeTwo(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        ListNode* temp = NULL;
        ListNode* head = NULL;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                if (!head) {
                    head = l1;
                    temp = l1;
                }else{
                    temp->next = l1;
                    temp = temp->next;
                }
                l1 = l1->next;
            } else {
                if (!head) {
                    head = l2;
                    temp = l2;
                }else{
                    temp->next = l2;
                    temp = temp->next;
                }
                l2 = l2->next;
            }
        }

        if(l1){
            temp->next = l1;
        }
        if(l2){
            temp->next = l2;
        }

        return head;
    }
    ListNode* partition(int start, int end, vector<ListNode*>& lists){
        if(start == end){
            return lists[start];
        }

        if(start>end){
            return nullptr;
        }

        int mid = start + (end-start)/2;

        ListNode* L1 = partition(start, mid, lists); //La
        ListNode* L2 = partition(mid+1, end, lists); //Lb

        return(mergeTwo(L1,L2));
    }

    
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.size()==0){
            return nullptr;
        }

        return(partition(0,lists.size()-1, lists));

    }
};