class Solution {
public:
    void backtrack(int openCount, int closeCount, int n, vector<string>& res, string st){
        if(openCount == n && closeCount == n){
            res.push_back(st);
            return;
        }

        if(openCount<n){
            backtrack(openCount+1, closeCount, n, res, st + "(");
        }

        if(closeCount<openCount){
            backtrack(openCount, closeCount+1, n, res, st + ")");
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string st = "";

        backtrack(0,0,n, res, st);
        return res;
    }
};