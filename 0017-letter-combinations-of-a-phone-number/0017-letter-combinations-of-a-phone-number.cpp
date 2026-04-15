class Solution {
public:
    vector<string> res;
    void dfs(string s, int i, string digits, unordered_map<char, string>mp){
        if(s.size() == digits.size()){
            res.push_back(s);
            return;
        }

        for(char c: mp[digits[i]]){
            dfs(s+c, i+1,digits,mp);
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        string s ="";
        dfs(s,0,digits,mp);
        return res;
    }
};