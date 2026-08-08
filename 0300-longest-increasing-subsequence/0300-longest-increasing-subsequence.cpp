class Solution {
public:
    int solve(vector<int>& nums, int i, int prev, vector<vector<int>>& dp) {
        if (i == nums.size()) {
            return 0; // no more elements to add so length is 0
        }
        // take ith element
        int take = 0;
        if (prev != -1 && dp[i][prev] != -1) {
            return dp[i][prev];
        }

        if (prev == -1 || nums[prev] < nums[i]) {
            take = 1 + solve(nums, i + 1, i, dp);
        }

        // skip ith element
        int skip = solve(nums, i + 1, prev, dp);

        if(prev != -1){
            dp[i][prev] = max(skip, take);
        }

        return max(skip, take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return(solve(nums, 0, -1, dp));
    }
};