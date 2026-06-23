class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int mid = 0;

        while(l<=r){
            mid = l +(r-l)/2;
            if(nums[mid] == target){
                return true;
            }else if(nums[l] ==  nums[mid]){
                l++;
            }else if(nums[l] < nums[mid]){ // left is sorted
                if(target >= nums[l] && target < nums[mid]){
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            }else{ // right is sorted
                if(target <= nums[r] && target > nums[mid]){
                    l = mid+1;
                }else{
                    r = mid-1;
                }
            }
        }
        return false; 
    }
};