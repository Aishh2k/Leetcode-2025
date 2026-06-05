class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int l = 0;
        int r = nums.size()-1;
        int count = 0;
        int sum;
        while(l<r){
            sum = nums[l] + nums[r];
            if(sum == k){
                count++;
                r--;
                l++;
            }else if(sum<k){
                l++;
            }else{
                r--;
            }
        }

        return count;
        
    }
};