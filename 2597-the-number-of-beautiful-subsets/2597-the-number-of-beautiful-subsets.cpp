class Solution {
public:
    int res = 0;
    void dfs( int idx, vector<int>&nums, int k, unordered_map<int, int>& mp){
        for(int i =idx;i<nums.size();i++){
            if(mp.find(nums[i] - k) == mp.end() && mp.find(nums[i] + k) == mp.end()){
                mp[nums[i]]++;
                res++;
                dfs(i+1, nums, k, mp);
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
            }
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        dfs(0, nums, k, mp);
        return res;
    }
};

/* Time Complexity
There are up to 2^n subsets, and in the worst case we explore all of them. The hash-map check is O(1) average, so time is O(2^n), and recursion/map space is O(n) */
