class Solution {
public:
    int helper(vector<int> nums){
        if(nums.size() == 1){
            return nums[0];
        }
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i =2;i<nums.size();i++){
            int steal = nums[i] + dp[i-2];
            int skip = dp[i-1];

            dp[i] = max(steal, skip);
        }

        return dp[nums.size()-1];

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }

        vector<int> takeFirst(nums.begin(), nums.end()-1);
        vector<int> skipFirst(nums.begin()+1, nums.end());

        return max(helper(takeFirst), helper(skipFirst));
    }
};