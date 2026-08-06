class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> arr(nums.size()+1, 0);
        // arr[i] = max stolen money till i house

        arr[1] = nums[0]; // only one house

        for(int i =2;i<=nums.size();i++){
            int steal = nums[i-1] + arr[i-2];
            int skip = arr[i-1];

            arr[i] = max(steal, skip);
        }

        return arr[nums.size()];
    }
};

//arr[0,1,0,0,0]
//nums [1,2,3,1]