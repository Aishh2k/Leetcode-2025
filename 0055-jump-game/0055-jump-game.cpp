class Solution {
public:
    bool canJump(vector<int>& nums) {

        int i =0;
        int jump =0;

        while(jump<=nums.size() && i<nums.size() && i<=jump){
            jump = max(jump, i+nums[i]);
            if(jump >= nums.size()-1){
                return true;
            }
            i++;
        }

        return false;
        
    }
};