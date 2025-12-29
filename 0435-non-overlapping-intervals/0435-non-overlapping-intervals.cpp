class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int count = 0;

        vector<int> cur = intervals[0];
        int i =1;
        while(i<intervals.size()){
            vector<int> next = intervals[i];
            if(cur[1]>next[0]){
                count++;
            }
            i++;
        }

        return count;
        
    }
};