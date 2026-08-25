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
    void dfs(Node* node, unordered_set<Node*>& visited, unordered_map<Node*, Node*>& mp){
        if(visited.count(node)){
            return;
        }
        visited.insert(node);
        Node* newNode = new Node(node->val);
        mp[node] = newNode;

        for(Node* nei : node->neighbors){
            dfs(nei, visited, mp);
        }
    }   
    Node* cloneGraph(Node* node) {
        if(!node){
            return nullptr;
        }
        unordered_set<Node*> visited;
        unordered_map<Node*, Node*> mp;

        dfs(node,visited,mp);

        for(auto nodes: mp){
            for(Node* nei: nodes.first->neighbors){
                nodes.second->neighbors.push_back(mp[nei]);
            }
        }

        return mp[node];
        
    }
};