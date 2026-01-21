class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum = 0;
        int count = 0;
        mp[sum]++;

        for(int i =0;i<nums.size();i++){
            sum += nums[i];
            int r = sum - k;
            if(mp.count(r)){
                count += mp[r];
            }
            mp[sum]++;
        }

        return count;
        
    }
};