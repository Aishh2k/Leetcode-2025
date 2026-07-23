class Solution {
public:
    void dfs(int i, vector<int>& nums ,int& x, int& res){
        if(i == nums.size()){
            res += x;
            return;
        }

        dfs(i+1, nums, x, res);
        x ^= nums[i];
        dfs(i+1, nums, x, res);
    }
    int subsetXORSum(vector<int>& nums) {
        int x = 0;
        int res = 0;
        dfs(0, nums, x, res);
        return res;
    }
};