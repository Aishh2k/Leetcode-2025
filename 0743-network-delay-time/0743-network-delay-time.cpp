class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        unordered_map<int, vector<pair<int, int>>> graph;

        for (auto i : times) {
            graph[i[0]].push_back(make_pair(i[1], i[2]));
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [cur_dist, node] = pq.top();
            pq.pop();

            if(cur_dist > dist[node]){
                continue;
            }

            for (auto [n, c] : graph[node]) {
                if(cur_dist + c < dist[n]){
                    dist[n] =  cur_dist + c;
                    pq.push({dist[n], n});
                }
            }
        }
        int m = 0;
        for(int i =1;i<dist.size();i++){
            if(dist[i] == INT_MAX){
                return -1;
            }

            m = max(dist[i], m);
        }

        return m;
    }
};