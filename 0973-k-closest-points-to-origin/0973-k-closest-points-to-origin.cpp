class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        for (auto i: points){
            int a = pow(i[0],2) + pow(i[1],2);
            pq.push(make_pair(a, vector<int>{i[0], i[1]}));

            if(pq.size()>k){
                pq.pop();
            }
        }

        vector<vector<int>> res;

        while(!pq.empty()){
            auto a = pq.top();
            res.push_back(a.second);
            pq.pop();
        }

        return res;
    }
};