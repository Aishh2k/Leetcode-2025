class Solution {
public:
    void dfs(int i, int sum, int target, vector<int>& nums, vector<vector<int>>& res, vector<int>& temp){
        if(sum == target){
            res.push_back(temp);
            return;
        }
        if(i == nums.size() || sum > target){
            return;
        }

        if(sum + nums[i] <= target){
            temp.push_back(nums[i]);
            dfs(i+1, sum + nums[i], target, nums, res, temp);
            temp.pop_back();
        }

        int next = i+1;

        while(next < nums.size() && nums[next] == nums[i]){
            next++;
        }

        dfs(next, sum, target, nums, res, temp);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        dfs(0, 0, target, candidates, res, temp);
        return res;
    }
};