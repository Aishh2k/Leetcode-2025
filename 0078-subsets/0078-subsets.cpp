class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int> res, vector<int> nums, int idx){
        if(idx == nums.size()){
            ans.push_back(res);
            return;
        }
        dfs(res,nums,idx+1);
        res.push_back(nums[idx]);
        dfs(res,nums,idx+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> res;
        dfs(res,nums,0);
        return ans;
    }
};