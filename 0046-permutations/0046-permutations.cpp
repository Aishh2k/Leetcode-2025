class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>& nums,
             vector<int>& temp, vector<bool> visited) {
        if (temp.size() == nums.size()) {
            res.push_back(temp);
            return;
        }

        for (int j = 0; j < nums.size(); j++) {
            if (!visited[j]) {
                temp.push_back(nums[j]);
                visited[j] = true;
                dfs(res, nums, temp, visited);
                visited[j] = false;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<bool> visited(nums.size(), false);

        dfs(res, nums, temp, visited);
        return res;
    }
};