class Solution {
public:
    bool canJump(vector<int>& nums) {
        int far = nums[0];
        for(int i =1;i<nums.size();i++){
            if(i>far){
                return false;
            }
            far = max(far, i+nums[i]);
        }

        return true;
        
    }
};