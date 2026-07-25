class Solution {
public:
    void dfs( int i, vector<int>&nums, vector<int>& temp, vector<vector<int>>&res){
        if(i == nums.size()){
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        dfs(i+1, nums, temp, res);
        temp.pop_back();

        int next = i+1;
        while(next<nums.size() && nums[next] == nums[i]){
            next++;
        }

        dfs(next, nums, temp, res);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        dfs(0, nums, temp, res);
        return res;
    }
};