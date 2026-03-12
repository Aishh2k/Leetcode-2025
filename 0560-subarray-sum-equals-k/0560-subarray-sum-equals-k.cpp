class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        int sum = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;

        for(int i =0;i<nums.size();i++){
            sum += nums[i];
            int rem = sum - k;

            if(mp.find(rem) != mp.end()){
                res += mp[rem];
            }
            mp[sum]++;
            
        }
        return res;  
    }
};