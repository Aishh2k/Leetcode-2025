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

        if(nums.size() == 1){
            return nums[0];
        }else if(nums.size() == 2){
            return max(nums[0], nums[1]);
        }
        
        vector<int> takeFirst(nums.size()-1);
        vector<int> skipFirst(nums.size()-1);

        for(int i =0;i<nums.size()-1;i++){ // creating two subarrays
            takeFirst[i] = nums[i];
            skipFirst[i] = nums[i+1];
        }

        return max(helper(takeFirst), helper(skipFirst));
    }
};