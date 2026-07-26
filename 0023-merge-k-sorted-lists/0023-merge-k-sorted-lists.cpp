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
    ListNode* merge(ListNode* L1, ListNode* L2){
        if(!L1){
            return L2;
        }
        if(!L2){
            return L1;
        }

        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;

        while(L1 && L2){
            if(L1->val > L2->val){
                temp->next = L2;
                L2 = L2->next;
            }else{
                temp->next = L1;
                L1 = L1->next;
            }
            temp = temp->next;
        }

        if(L1){
            temp->next = L1;
        }
        if(L2){
            temp->next = L2;
        }

        return dummy->next;
    }
    ListNode* partition(int start, int end, vector<ListNode*>& lists){
        if(start == end){
            return lists[start];
        }
        if(start > end){
            return nullptr;
        }

        int mid = start + (end-start)/2;
        ListNode* L1 = partition(start, mid, lists);
        ListNode* L2 = partition(mid+1, end, lists);

        return(merge(L1, L2));

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return nullptr;
        }
        if(lists.size() == 1){
            return lists[0];
        }

        return partition(0, lists.size()-1, lists);
    }
};