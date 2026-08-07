class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long answer = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                answer += nums[i] - nums[i - 1];
            }
        }

        return answer;
    }
};