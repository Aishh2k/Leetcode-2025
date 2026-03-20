class Solution {
public:
    bool dfs(int u, int v, unordered_map<int, vector<int>>& graph, unordered_set<int> & visited) {
        if (u == v) {
            return true;
        }
        visited.insert(u);
        for (auto nei : graph[u]) {
            if(!visited.count(nei)){
                if(dfs(nei,v, graph, visited)){
                    return true;
                }
            }
        }

        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            unordered_set<int> visited;
            if (graph.size()!=0 && dfs(u, v, graph, visited)) {
                return {u,v};
            } else {
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
        }
        return {-1,-1};
    }
};