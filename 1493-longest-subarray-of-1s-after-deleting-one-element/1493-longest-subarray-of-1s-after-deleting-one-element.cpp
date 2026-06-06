class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l =0;
        int r = 0;
        int maxLength = 0;

        bool zero = false;

        while(r<nums.size()){
            if(nums[r] == 0){
                if(!zero){
                    zero = true;
                }else{
                    while(nums[l] != 0){
                        l++;
                    }
                    l++;
                }
            }
            maxLength = max(maxLength, r-l);
            r++;
        }
        return maxLength;
        
    }
};