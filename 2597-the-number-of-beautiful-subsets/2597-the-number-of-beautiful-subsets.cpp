class Solution {
public:
    int ans = 0;
    void dfs(int idx, unordered_map<int, int>& mp, vector<int>&nums, int k){
        for(int i  = idx;i<nums.size();i++){
            if(mp.find(nums[i] -k) == mp.end() && mp.find(nums[i] + k) == mp.end()){
                ans++;
                mp[nums[i]]++;
                dfs(i+1, mp, nums, k);
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
            }
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        dfs(0, mp, nums, k);
        return ans;
    }
};