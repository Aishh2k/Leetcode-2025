class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        sort(intervals.begin(), intervals.end());
        vector<int> cur = intervals[0];

        for(int i = 1;i<intervals.size();i++){
            if(cur[1]>intervals[i][0]){
                ans++;
                cur[1] = min(cur[1], intervals[i][1]);
            }else{
                cur = intervals[i];
            }
        }
        return ans;
        
    }
};

