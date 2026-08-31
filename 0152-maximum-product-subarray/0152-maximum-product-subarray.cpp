class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_p = nums[0];
        int min_p = nums[0];
        int ans = nums[0];

        for(int i = 1;i<nums.size();i++){
            int temp = min_p;
            min_p = min({nums[i], max_p * nums[i], min_p *nums[i]});
            max_p = max({nums[i], max_p * nums[i], temp * nums[i]});
            ans = max(ans, max_p);
        }   
        return ans;
        
    }
};