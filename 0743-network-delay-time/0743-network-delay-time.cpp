class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,INT_MAX);
        dist[k]= 0;
        vector<vector<pair<int,int>>> graph(n+1);

        for(auto t:times){
            graph[t[0]].push_back({t[1], t[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push({0,k});

        while(!q.empty()){
            auto [cur_dist, node ] = q.top();
            q.pop();
            for(auto [nei, nei_dist]: graph[node]){
                if(cur_dist + nei_dist < dist[nei]){
                    dist[nei] = min(dist[nei], cur_dist + nei_dist);
                    q.push({dist[nei], nei});
                }
            }
        }
        int res = 0;
        for(int i =1;i<=n;i++){
            if(dist[i] == INT_MAX){
                return -1;
            }

            res = max(res,dist[i]);
        }

        return res;
        
    }
};