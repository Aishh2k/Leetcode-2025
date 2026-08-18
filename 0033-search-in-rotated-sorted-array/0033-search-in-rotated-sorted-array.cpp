class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;

        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target){
                return mid;
            }else if (nums[mid] >= nums[low]){ // left is sorted
                if(target <= nums[mid] && target >= nums[low]){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }else{ // right is sorted
                if(target <= nums[high] && target > nums[mid]){ // in the sorted half
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
        }

        return -1;
        
    }
};

// 12345
// 45123 n = 3