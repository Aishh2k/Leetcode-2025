/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return NULL;
        }
        queue<Node*>q;
        unordered_set<Node*> visited;
        unordered_map<Node*, Node*>mp;
        visited.insert(node);
        q.push(node);
        mp[node] = new Node(node->val);

        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            for(Node* n: node->neighbors){
                if(!visited.count(n)){
                    mp[n] = new Node(n->val);
                    visited.insert(n);
                    q.push(n);
                }
            }
        }

        for(Node* n: visited){
            for(Node* nei: n->neighbors){
                mp[n]->neighbors.push_back(mp[nei]);
            }
        }

        return mp[node];
    }
};