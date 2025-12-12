#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> arr;
        for (int i=0;i<nums.size();i++){
            int com = target - nums[i];
            if(arr.find(com)!= arr.end()){
                return {arr[com], i};
            }else{
                arr[nums[i]] = i;
            }

        }
        return {} ;
    }
};