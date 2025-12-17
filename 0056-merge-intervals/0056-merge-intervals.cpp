class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        vector<int> cur = intervals[0];

        for(int i =1;i<intervals.size();i++){
            vector<int> next = intervals[i];
            if(cur[1]>=next[0]){
                cur[1] = max(cur[1], next[1]);
                
            }else{
                res.push_back(cur);
                cur = next;
            }
        }
        res.push_back(cur);
        return res;

        
    }
};