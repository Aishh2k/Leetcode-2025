class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        int sum = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;

        for(int i =0;i<nums.size();i++){
            sum += nums[i];
            int prefix = sum - k;

            if(mp.find(prefix)!=mp.end()){
                res += mp[prefix];
            }

            mp[sum]++;
        }

        return res;
        
    }
};