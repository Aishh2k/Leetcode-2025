class Solution {
public:
    void dfs( int i, int k, int n, vector<vector<int>>& res, vector<int>&temp){
        if(temp.size() == k){
            res.push_back(temp);
            return;
        }
        if(i > n){
            return;
        }

        temp.push_back(i);
        dfs(i+1, k, n, res, temp);
        temp.pop_back();
        dfs(i+1, k, n, res, temp);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>res;
        vector<int> temp;
        dfs(1, k, n, res, temp);
        return res;
    }
};