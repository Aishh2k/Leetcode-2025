class Solution {
public:
    bool dfs(int a, int b, unordered_map<int, vector<int>> graph,
             unordered_set<int>& visited) {
        if (a == b) {
            return true;
        }
        visited.insert(a);
        for(int nei : graph[a]){
            if(!visited.count(nei)){
                bool val = dfs(nei, b, graph, visited);
                if(val){
                    return true;
                }else{
                    continue;
                }
            }
        }

        return false;

    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& p,
                                     vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> graph;
        vector<bool> ans;

        for (auto i : p) {
            graph[i[0]].push_back(i[1]);
        }

        for (auto i : queries) {
            unordered_set<int> visited;
            if (graph.find(i[0]) == graph.end()) {
                ans.push_back(false);
            } else {
                bool val = dfs(i[0], i[1], graph, visited);
                ans.push_back(val);
            }
        }

        return ans;
    }
};