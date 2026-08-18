class Solution {
public:
    vector<vector<int>> result;
    void dfs(int start, vector<int>& temp, vector<int>& c, int target){
        if(target == 0){
            result.push_back(temp);
            return;
        }

        for(int i = start;i<c.size();i++){
            if(target - c[i] >= 0){
                temp.push_back(c[i]);
                dfs(i, temp, c, target - c[i]);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        vector<int> temp;
        dfs(0, temp, c, target);
        return result;
    }
};