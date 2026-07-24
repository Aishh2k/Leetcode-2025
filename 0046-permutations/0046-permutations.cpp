class Solution {
public:
    void dfs(vector<int>& nums, vector<int>& temp, vector<vector<int>>& res, vector<bool>& visited){
        if(temp.size()== nums.size()){
            res.push_back(temp);
            return;
        }

        for(int i = 0;i<nums.size();i++){
            if(!visited[i]){
                temp.push_back(nums[i]);
                visited[i] = true;
                dfs(nums, temp, res, visited);
                visited[i] = false;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<bool> visit(nums.size(), false);
        dfs(nums, temp, res, visit);
        return res;
    }
};