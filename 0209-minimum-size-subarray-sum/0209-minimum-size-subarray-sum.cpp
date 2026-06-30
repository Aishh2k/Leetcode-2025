class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int r = 0;
        int ans = INT_MAX;
        int sum = 0;

        while(l<nums.size()){
            sum += nums[l];
            while(sum>= target){
                ans = min(ans, l-r+1);
                sum -= nums[r];
                r++;
            }
            l++;
        }
        if(ans == INT_MAX) return 0;
        else return ans;
    }
};