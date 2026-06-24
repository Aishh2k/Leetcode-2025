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
        Node* dummy = new Node(0);
        Node* newTemp = dummy;

        while(temp){
            Node* node = new Node(temp->val);
            newTemp->next = node;
            newTemp = newTemp->next;
            mp[temp] = node;
            temp = temp->next;
        }

        newTemp = dummy->next;
        temp = head;

        while(temp){
            newTemp->random = mp[temp->random];
            newTemp = newTemp->next;
            temp = temp->next;
        }
        return dummy->next;
        
    }
};