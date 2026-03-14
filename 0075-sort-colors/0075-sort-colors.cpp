class Solution {
public:
    void sortColors(vector<int>& nums) {
        int o =0;
        int t = nums.size()-1;
        int i =0;

        while(i<nums.size() && i<=t){
            if(nums[i] == 0){
                swap(nums[i++], nums[o++]);
            }else if(nums[i]==2){
                swap(nums[i], nums[t--]);
            }else{
                i++;
            }
        }
        
    }
};