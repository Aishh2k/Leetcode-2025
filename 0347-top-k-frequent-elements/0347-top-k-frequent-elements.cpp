class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int> mp;

        for(int i : nums){
            mp[i] ++;
        }

        for(auto i: mp){
            pq.push(make_pair(i.second, i.first));
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            auto [freq,val] = pq.top();
            ans.push_back(val);
            pq.pop();
        }

        return ans;


        
    }
};