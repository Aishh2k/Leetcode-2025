class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int s = nums.size();
        unordered_map<int, int> mp;
        for(int n: nums){
            mp[n]++;
            if(mp[n]> int(s/2)){
                return n;
            }
        }

        for(auto i: mp){
            if(i.second> int(s/2)){
                return i.first;
            }
        }

        return -1;
        
    }
};