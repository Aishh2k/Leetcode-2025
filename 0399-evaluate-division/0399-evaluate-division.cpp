class Solution {
public:
    double dfs(string a, string b, unordered_set<string>& visited,
               unordered_map<string, vector<pair<string, double>>>& graph) {
        if(!graph.count(a) || !graph.count(b)){
            return -1.0;
        }
        if(a==b){
            return 1.0;
        }
        visited.insert(a);
        for (auto [nei, val] : graph[a]) {
            if(!visited.count(nei)){
                double res = dfs(nei,b, visited, graph);
                if(res != -1.0){
                    return(val * res);
                }
            }
        }

        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& e,
                                vector<double>& values,
                                vector<vector<string>>& queries) {

        // generate the graph
        unordered_map<string, vector<pair<string, double>>> graph;
        for (int i =0;i<e.size();i++) {
            graph[e[i][0]].push_back({e[i][1], values[i]});
            graph[e[i][1]].push_back({e[i][0], 1.0 / values[i]});
        }

        //dfs traversal
        vector<double> res;
        for (auto i : queries) {
            unordered_set<string> st;
            res.push_back(dfs(i[0], i[1], st, graph));
        }

        return res;
    }
};