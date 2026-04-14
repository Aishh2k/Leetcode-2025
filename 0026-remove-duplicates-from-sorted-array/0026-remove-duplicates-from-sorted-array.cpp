class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l =0;
        int r = 1;

        while(r<nums.size()){
            if(nums[l] != nums[r]){
                nums[++l] = nums[r];
            }
            r++;
        }
        return l+1;
        
    }
};