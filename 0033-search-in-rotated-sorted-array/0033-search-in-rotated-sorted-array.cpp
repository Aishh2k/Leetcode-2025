class Solution {
public:
    int search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size()-1;
        int mid = 0;

        while(low<=high){
            mid = low + (high-low)/2;

            if(target == nums[mid]){
                return mid;
            }else if(nums[mid]>= nums[low]){ // left side is sorted
                if(target >= nums[low] && target <= nums[mid]){ // check if target in sorted half
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }else{ // right side is sorted
                 if(target >= nums[mid] && target <= nums[high]){ // check if target in sorted half
                    low = mid+1;
                }else{
                    high = mid-1;
                }   
            }
        }

        return -1;
        
    }
};