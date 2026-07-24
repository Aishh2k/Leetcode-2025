class Solution {
public:
    void dfs (int open, int close, string temp, int n, vector<string>& res){
        if(open == n && close == n){
            res.push_back(temp);
            return;
        }
        if(open < n){
            dfs(open+1, close, temp + "(", n,  res);
        }
        if(close<open){
            dfs(open, close+1, temp + ")",n,  res);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(0, 0, "", n, res);
        return res;
    }
};