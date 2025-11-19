class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int r = 0;
        int n = nums.size();
        if(n<=1){
            return;
        }

        for(int l =0;l<n;l++){
            if(nums[l] !=0){
                swap(nums[l], nums[r]);
                r++;
            }
            
        }
        
    }
};