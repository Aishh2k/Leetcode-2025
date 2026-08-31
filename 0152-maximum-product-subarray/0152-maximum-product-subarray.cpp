class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_p = nums[0];
        int min_p = nums[0];
        int ans = nums[0];

        for(int i = 1;i<nums.size();i++){
            int temp = min_p;
            min_p = min({nums[i], nums[i] * max_p, nums[i] * min_p});
            max_p = max({nums[i], nums[i] * max_p, nums[i] * temp});

            ans = max(max_p, ans);
        }

        return ans;
        
    }
};