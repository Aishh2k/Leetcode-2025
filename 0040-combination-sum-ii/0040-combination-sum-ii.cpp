class Solution {
public:
    vector<vector<int>> result;
    void dfs(int idx, int target, vector<int>& temp,vector<int>&c){
        if(target == 0){
            result.push_back(temp);
            return;
        }

        for(int i = idx;i<c.size();i++){
            if(i > idx && c[i] == c[i-1]){
                continue;
            }
            if(target - c[i] >=0){
                temp.push_back(c[i]);
                dfs(i+1, target - c[i], temp, c);
                temp.pop_back();
            }
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        sort(c.begin(), c.end());
        vector<int> temp;
        dfs(0,target, temp, c);
        return result;
    }
};