class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0;
        int temp;
        for(int r = 0;r<nums.size();r++){ // 0
            if(nums[r] == 0){
                temp = nums[l];
                nums[l] = nums[r];
                nums[r] = temp;
                l++;
            }
        }

        for(int r = l;r<nums.size();r++){
            if(nums[r] == 1){
                temp = nums[l];
                nums[l] = nums[r];
                nums[r] = temp;
                l++;
            }
        }
    }
};