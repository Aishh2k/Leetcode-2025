class Solution {
public:
    vector<vector<int>> result;
    void dfs(int idx, vector<int>& nums, int target, int sum, vector<int>& temp){
        if(sum == target){
            result.push_back(temp);
            return;
        }

        for(int i = idx;i<nums.size();i++){
            if(i>idx && nums[i] == nums[i-1]){
                continue;
            }

            if(sum + nums[i] <= target){
                temp.push_back(nums[i]);
                dfs(i+1, nums, target, sum + nums[i], temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int sum = 0;
        vector<int> temp;
        dfs(0, candidates,target, sum, temp);
        return result;
    }
};