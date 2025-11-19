class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;

        for(int i: nums){
            res.push_back(i);
        }
        for(int i: nums){
            res.push_back(i);
        }
        return res;
    }
};