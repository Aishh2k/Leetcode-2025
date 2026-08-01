class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<int> cur = intervals[0];
        int c = 0;

        for(int i =1;i<intervals.size();i++){
            if(cur[1] > intervals[i][0]){
                cur[1] =  min(intervals[i][1], cur[1]);
                c++;
            }else{
                cur = intervals[i];
            }
        }
        return c;


        
    }
};