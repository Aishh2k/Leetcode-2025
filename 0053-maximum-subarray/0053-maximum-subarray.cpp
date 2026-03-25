class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = nums[0];
        int res = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            curSum = max(nums[i], curSum + nums[i]);
            if (curSum > res) {
                res = curSum;
            }
        }

        return res;
    }
};