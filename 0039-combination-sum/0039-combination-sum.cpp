class Solution {
public:
    void dfs(int i, vector<vector<int>>& res, int sum, vector<int>& nums, int target, vector<int>& temp){
        if(sum == target){
            res.push_back(temp);
            return;
        }
        if(i == nums.size()){
            return;
        }

        if(sum + nums[i] <= target){
            temp.push_back(nums[i]);
            dfs(i, res, sum + nums[i], nums, target, temp);
            temp.pop_back();
        }
        dfs(i+1, res, sum, nums, target, temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        int sum = 0;
        vector<int> temp;
        dfs(0, res, sum, candidates, target, temp);
        return res;
    }
};