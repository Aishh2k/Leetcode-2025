class Solution {
public:
    void dfs(int i, vector<int>& nums, vector<int>&temp, vector<vector<int>>&res){
        if(i == nums.size()){
            res.push_back(temp);
            return;
        }

        dfs(i+1, nums, temp, res);
        temp.push_back(nums[i]);
        dfs(i+1, nums, temp, res);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        dfs(0, nums, temp, res);
        return res;
    }
};