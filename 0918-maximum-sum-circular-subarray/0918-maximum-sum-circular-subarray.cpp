class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int maxSum = nums[0];
        int maxSub = nums[0];

        int minSum = nums[0];
        int minSub = nums[0];
        int total = nums[0];

        for(int i = 1;i<nums.size();i++){
            total += nums[i];

            if(nums[i] + maxSum < nums[i]){
                maxSum = nums[i];
            }else{
                maxSum += nums[i];
            }

            if(nums[i] + minSum > nums[i]){
                minSum = nums[i];
            }else{
                minSum += nums[i];
            }

            maxSub = max(maxSub, maxSum);
            minSub = min(minSub, minSum);
        }

        if(maxSub < 0){
            return maxSub;
        }

        int cirSum = total - minSub;

        return max(cirSum, maxSub);
        
    }
};