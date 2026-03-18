class Solution {
public:
    bool canJump(vector<int>& nums) {

        int i =0;
        int jump =0;

        while(i<nums.size() && i<=jump){
            jump = max(jump, i+nums[i]);
            if(jump >= nums.size()-1){
                return true;
            }
            if(i<jump){
                i++;
            }
        }

        return false;
        
    }
};