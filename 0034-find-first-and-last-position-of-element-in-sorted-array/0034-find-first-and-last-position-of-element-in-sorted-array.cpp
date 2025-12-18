class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        bool isFirst = true;
        int fid = binarySearch(nums, target, isFirst);
        int lid = binarySearch(nums, target, !isFirst);

        return{fid, lid};
    }

    int binarySearch(vector<int>& nums, int target, bool isFirst){
        int idx = -1;
        int low = 0;
        int high = nums.size() -1;
        int mid;

        while(low<=high){
            mid = low + (high-low)/2;
            if(target>nums[mid]){
                low = mid+1;
            }else if (target<nums[mid]){
                high = mid-1;
            }else{
                idx = mid;
                if(isFirst){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }
        }
        return idx;
    }
};