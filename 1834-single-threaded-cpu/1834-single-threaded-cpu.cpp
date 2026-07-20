class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<vector<int>> T;
        int n = tasks.size();

        for(int i =0;i<n;i++){
            int start_time = tasks[i][0];
            int proc_time = tasks[i][1];

            T.push_back({start_time, proc_time, i});
        }
        long long cur_time = 0;
        int idx = 0;
        sort(T.begin(), T.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> res;

        while(idx<n || !pq.empty()){
            if(pq.empty() && idx<n && cur_time<T[idx][0]){ //idle cur time is 5 and next availabel task is starting at 20, then you wanna jump to 20
                cur_time = T[idx][0];
            }

            while(idx<n && T[idx][0] <= cur_time){
                pq.push({T[idx][1], T[idx][2]});
                idx++;
            }
            auto[dur, pos] = pq.top();
            pq.pop();
            cur_time += dur;
            res.push_back(pos);
        }
        return res;
    }
};