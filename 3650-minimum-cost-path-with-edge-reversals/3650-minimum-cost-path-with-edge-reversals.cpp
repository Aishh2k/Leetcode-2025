class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        // make graph
        unordered_map<int, vector<pair<int, int>>> graph; // direct
        unordered_map<int, vector<pair<int, int>>> rev;   // indirect

        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            int w = edges[i][2];

            graph[a].push_back({b, w});
            rev[b].push_back({a, 2 * w});
        }

        vector<int> d(n, INT_MAX);
        d[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        pq.push({0, 0}); // (cost 0, node 0)

        while (!pq.empty()) {
            auto [c, a] = pq.top();
            pq.pop();

            if(c>d[a]){
                continue;
            }
            if (a == n - 1) {
                return c;
            }

            for (auto nei : graph[a]) {
                if (d[a] != INT_MAX && d[a] + nei.second < d[nei.first]) {
                    d[nei.first] =
                        min(d[nei.first], nei.second + d[a]);
                    pq.push({d[nei.first], nei.first});
                }
            }

            for (auto nei : rev[a]) {
                if (d[a] != INT_MAX && d[a] + nei.second < d[nei.first]) {
                    d[nei.first] =
                        min(d[nei.first], nei.second + d[a]);
                    pq.push({d[nei.first], nei.first});
                }
            }
        }

        return -1;
    }
};