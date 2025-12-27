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
        Node* temp = head;
        Node* newHead = NULL;
        Node* trav = NULL;
        unordered_map<Node*, Node*> mp;

        while(temp){
            Node* node = new Node(temp->val);
            mp[temp] = node;

            if(!newHead){
                newHead = node;
                trav = node;
            }else{
                trav->next = node;
                trav = trav->next;
            }

            temp = temp->next;
        }

        trav = newHead;
        temp = head;
        while(temp){
            trav->random = mp[temp->random];
            trav = trav->next;
            temp = temp->next;
        }

        return newHead;
        
    }
};