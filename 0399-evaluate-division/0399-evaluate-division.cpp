class Solution {
public:
    double dfs(string e, string f,
               unordered_map<string, vector<pair<string, double>>>& graph,
               unordered_set<string>& visited) {
        if (e == f) {
            return 1.0;
        }

        visited.insert(e);

        for (auto i : graph[e]) {
            if (visited.count(i.first)) {
                continue;
            }
            double ans = dfs(i.first, f, graph, visited);
            if (ans != -1.0) {
                return (i.second * ans);
            }
        }

        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;

        for (int i = 0; i < values.size(); i++) {
            graph[equations[i][0]].push_back(
                make_pair(equations[i][1], values[i]));
            graph[equations[i][1]].push_back(
                make_pair(equations[i][0], 1.0 / values[i]));
        }

        vector<double> ans;
        for (int i = 0; i < queries.size(); i++) {
            if (!graph.count(queries[i][0]) || !graph.count(queries[i][1])) {
                ans.push_back(-1.0);
            } else {
                unordered_set<string> visited;
                ans.push_back(dfs(queries[i][0], queries[i][1], graph, visited));
            }
        }

        return ans;
    }
};