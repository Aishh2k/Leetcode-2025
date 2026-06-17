class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> ans;

        for(int i =0;i<nums.size();i++){
            int rem = target - nums[i];
            if(mp.find(rem) != mp.end()){
                ans.push_back(i);
                ans.push_back(mp[rem]);
                return ans;
            }
            mp[nums[i]] = i;
        }

        return {-1,-1};
        
    }
};