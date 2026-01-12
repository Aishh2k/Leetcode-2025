class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int curSum = nums[0];

        if(nums.size()<2){
            return nums[0];
        }

        for (int i = 1; i < nums.size(); i++) {
            curSum = max(nums[i], curSum + nums[i]);
            maxSum = max(curSum, maxSum);
        }

        return maxSum;
    }
};