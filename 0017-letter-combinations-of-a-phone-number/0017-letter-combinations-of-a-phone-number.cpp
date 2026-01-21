class Solution {
public:
    vector<string> ans;
    void backtrack(string digits, int i, string sol, int n, unordered_map<char, string> mp){
        if(i==n){
            ans.push_back(sol);
            return;
        }
        for(auto c : mp[digits[i]]){
            backtrack(digits, i+1, sol + c, n, mp);
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mp;
        int i =0;
        string str = "";

        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        backtrack(digits, i, str, digits.size(), mp);
        return ans;
        
    }
};