class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int count = 0;
        mp[0] = 1;
        int sum = 0;

        for(int i: nums){
            sum += i;
            int rem = sum-k;
            if(mp.find(rem) != mp.end()){
                count += mp[rem];
            }
            mp[sum]++;
        }
        return count;
    }
};