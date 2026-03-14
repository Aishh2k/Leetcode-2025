/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        Node* temp = head;

        Node* newHead = NULL;
        Node* newTemp = NULL;

        while(temp){
            Node* node = new Node(temp->val);
            mp[temp] = node;

            if(!newHead){
                newHead = node;
                newTemp = node;
            }else{
                newTemp->next = node;
                newTemp = newTemp->next;
            }

            temp = temp->next;
        }

        temp = head;
        newTemp = newHead;

        while(temp){
            newTemp->random = mp[temp->random];
            newTemp = newTemp->next;
            temp = temp->next;
        }
        return(newHead); 
    }
};