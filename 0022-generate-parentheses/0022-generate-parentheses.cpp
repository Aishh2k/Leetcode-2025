class Solution {
public:
    vector<string> res;

    void recur(int n , string s, int open, int close){
        if(open == n && close == n){
            res.push_back(s);
            return;
        }

        if(open<n){
            recur(n,s+"(", open+1, close);
        }

        if(close<open){
            recur(n, s+")", open, close+1);
        }
    }

    vector<string> generateParenthesis(int n) {
        string s = "";
        recur(n,s,0,0);
        return res;
    }
};