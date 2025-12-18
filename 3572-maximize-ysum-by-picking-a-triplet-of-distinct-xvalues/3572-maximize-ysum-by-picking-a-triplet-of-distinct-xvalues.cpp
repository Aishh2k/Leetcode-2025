class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        unordered_map<int,int> mp;
        for(int i =0;i<x.size();i++){
            if(!mp.count(x[i])){
                mp[x[i]] = y[i];
            }else{
                mp[x[i]] = max(y[i], mp[x[i]]);
            }
        }

        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto i: mp){
            pq.push(i.second);
            if(pq.size()>3){
                pq.pop();
            }
        }

        if(pq.size()<3){
            return -1;
        }else{
            int sum = 0;
            while(!pq.empty()){
                sum += pq.top();
                pq.pop();
            }
            return sum;
        }
        
    }
};