class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<vector<long long>> dp(nums.size(), vector<long long> (2,0));

        dp[0][0] = 0;
        dp[0][1] = nums[0];

        for(int i =1;i<nums.size();i++){
            // even length substring
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] - nums[i]);


            /// odd length substring
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + nums[i]);
        }

        return (max(dp[nums.size()-1][0], dp[nums.size()-1][1]));
        
    }
};