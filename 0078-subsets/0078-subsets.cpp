class Solution {
public:
    vector<vector<int>> result;
    void dfs(vector<int> nums, vector<int> res, int i){
        if(i == nums.size()){
            result.push_back(res);
            return;
        }

        dfs(nums, res, i+1); // dont take it
        res.push_back(nums[i]);
        dfs(nums, res, i+1); // take it

    }
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int> res;
        dfs(nums,res,0);
        return result;
        
    }
};