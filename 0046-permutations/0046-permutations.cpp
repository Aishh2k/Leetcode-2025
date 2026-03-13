class Solution {
public:
    vector<vector<int>> result;
    void dfs(vector<int> nums, vector<int> res, vector<bool> visited) {
        if (res.size() == nums.size()) {
            result.push_back(res);
            return;
        }

        for (int i =0;i<nums.size();i++) {
            if(!visited[i]){
                res.push_back(nums[i]);
                visited[i] = true;
                dfs(nums, res,visited);
                visited[i] = false;
                res.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> res;
        vector<bool> visited(nums.size(), false);
        dfs(nums, res, visited);
        return result;
    }
};