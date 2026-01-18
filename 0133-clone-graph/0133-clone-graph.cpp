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
            return node;
        }

        unordered_map<Node*, Node*> mp;
        unordered_set<Node*> visited;
        stack<Node*> stk;

        stk.push(node);
        visited.insert(node);

        while(!stk.empty()){
            Node* cur = stk.top();
            stk.pop();
            mp[cur] = new Node(cur->val);

            for(Node* nei : cur->neighbors){
                if(!visited.count(nei)){
                    visited.insert(nei);
                    stk.push(nei);
                }
            }
        }

        for(auto n : mp){
            for(Node* nei : n.first->neighbors){
                Node* new_nei = mp[nei];
                n.second->neighbors.push_back(new_nei);
            }
        }

        return(mp[node]);

        
    }
};