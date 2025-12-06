class Solution {
public:
    int findMin(vector<int>& nums) {

        int ans = 5000;
        int low = 0;
        int high = nums.size()-1;
        int mid = 0;

        while(low<=high){
            mid = low + (high -low)/2;

            if(nums[low]<= nums[mid]){ // left sorted
                ans = min(ans, nums[low]);
                low = mid+1;
            }else{
                ans = min(ans, nums[mid]);
                high = mid-1;
            }
        }


        return ans;
        
    }
};