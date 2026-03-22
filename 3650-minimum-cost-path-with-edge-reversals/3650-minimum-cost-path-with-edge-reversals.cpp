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
            auto [cur_dist, cur_node] = pq.top();
            pq.pop();

            if(cur_dist>d[cur_node]){ // old cost which is not usefull
                continue;
            }

            if (cur_node == n - 1) {
                return cur_dist;
            }

            for (auto [nei_node, nei_dist] : graph[cur_node]) {
                if (cur_dist + nei_dist < d[nei_node]) {
                    d[nei_node] = cur_dist + nei_dist;
                    pq.push({d[nei_node], nei_node});
                }
            }

            for (auto [nei_node, nei_dist] : rev[cur_node]) {
                if (cur_dist + nei_dist < d[nei_node]) {
                    d[nei_node] = cur_dist + nei_dist;
                    pq.push({d[nei_node], nei_node});
                }
            }
        }

        return -1;
    }
};