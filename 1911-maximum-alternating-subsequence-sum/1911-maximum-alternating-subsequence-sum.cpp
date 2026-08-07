class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> t(n, vector<long long>(2,0));
        t[0][0] = 0;
        t[0][1] = nums[0];

        for(int i =1;i<n;i++){
            // even length final array
            t[i][0] = max(t[i-1][0], t[i-1][1] - nums[i]);

            //odd length final array
            t[i][1] = max(t[i-1][1], t[i-1][0] + nums[i]);
        }

        return max(t[n-1][0], t[n-1][1]);
        
    }
};