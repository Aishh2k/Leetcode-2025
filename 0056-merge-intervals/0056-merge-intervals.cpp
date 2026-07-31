class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<int> cur = intervals[0];
        vector<vector<int>> res;

        int i = 1;
        while(i<intervals.size()){
            if(cur[1] >= intervals[i][0]){
                cur[0] = min(cur[0], intervals[i][0]);
                cur[1] = max(cur[1], intervals[i][1]);
            }else{
                res.push_back(cur);
                cur = intervals[i];
            }
            i++;
        }
        res.push_back(cur);
        return res;
    }
};