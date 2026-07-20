class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<vector<int>> T;
        for(int i =0;i<tasks.size();i++){
            T.push_back({tasks[i][0], tasks[i][1], i});
        }
        long long cur_time = 0;
        sort(T.begin(), T.end()); // sorted based off the start Time of tasks
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> res;

        int idx =0;
        while(idx<T.size() || !pq.empty()){
            if(pq.empty() && cur_time<T[idx][0]){
                cur_time = T[idx][0];
            }
            while(idx<T.size() && T[idx][0] <= cur_time){
                pq.push({T[idx][1], T[idx][2]});
                idx++;
            }

            auto [dur, pos] = pq.top();
            pq.pop();
            cur_time += dur;
            res.push_back({pos});
        }

        return res;
    }
};