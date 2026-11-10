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
    void dfs(Node* node, unordered_map<Node*, Node*>& mp){
        if(!node){
            return;
        }

        Node* newNode = new Node(node->val);
        mp[node] = newNode;

        for(auto nei: node->neighbors){
            if(mp.find(nei) == mp.end()){
                dfs(nei, mp);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node){
            return NULL;
        }

        if(!node->neighbors.size()){
            Node* newNode  = new Node(node->val);
            return newNode;
        }

        Node* temp = node;
        unordered_map<Node*, Node*> mp;

        dfs(node, mp);

        for(auto pair: mp){
            for(auto nei: pair.first->neighbors){
                pair.second->neighbors.push_back(mp[nei]);
            }
        }

        return mp[node];

    }
};