class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> res;

        for(int i : nums){
            mp[i]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto a: mp){
            pq.push(make_pair(a.second, a.first));
            if(pq.size()>k){
                pq.pop();
            }
        }


        while(!pq.empty()){
            pair<int,int> a = pq.top();
            res.push_back(a.second);
            pq.pop();
        }

        return res;
    }
};