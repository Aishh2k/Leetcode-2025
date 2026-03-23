class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }else if(nums.size()==2){
            return max(nums[0], nums[1]);
        }
        
        vector<int> house(nums.size(),INT_MAX);
        house[0] = nums[0];
        house[1] = max(nums[0], nums[1]);

        if(nums.size()<3){
            return house[nums.size()-1];
        }

        for(int i =2;i<nums.size();i++){
            house[i] = max(nums[i]+ house[i-2], house[i-1]);
        }

        return(house[nums.size()-1]);
        
    }
};