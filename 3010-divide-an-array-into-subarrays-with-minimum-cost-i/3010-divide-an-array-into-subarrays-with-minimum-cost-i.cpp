class Solution {
public:
    int minimumCost(vector<int>& nums) {

        int sum = nums[0];
        vector<int> s;

        for(int i =1;i<nums.size();i++){
            s.push_back(nums[i]);
        }

        sort(s.begin(), s.end());

        sum += s[0]+s[1];

        return sum;
        
    }
};