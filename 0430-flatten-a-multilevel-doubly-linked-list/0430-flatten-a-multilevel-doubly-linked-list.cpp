/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* resHead = head;
        Node* temp = head;
        while (temp!= NULL) {
            if (temp->child == NULL) {
                temp = temp->next;
            } else {
                Node* next = temp->next;
                Node* child = flatten(temp->child);
                temp->next = child;
                child->prev = temp;
                temp->child = NULL;
                while(temp->next != NULL){
                    temp = temp->next;
                }
                if(next != NULL){
                    temp->next = next;
                    next->prev = temp;
                }
                temp = temp->next;
            }
        }

        return resHead;
    }
};