class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int curr_i = n - 1; curr_i >= 0; curr_i--) {
            for (int prev_i = curr_i - 1; prev_i >= -1; prev_i--) {
                int take = 0;
                if (prev_i == -1 || nums[prev_i] < nums[curr_i])
                    take = 1 + dp[curr_i + 1][curr_i + 1];

                int skip = dp[curr_i + 1][prev_i + 1];

                dp[curr_i][prev_i + 1] = max(take, skip);
            }
        }

        return dp[0][0];
    }
};