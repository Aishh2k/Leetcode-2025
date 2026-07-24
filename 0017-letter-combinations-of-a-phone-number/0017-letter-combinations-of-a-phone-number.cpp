class Solution {
public:
    void dfs(int i, string digits, string& temp, vector<string>& res, unordered_map<char, string>& mp){
        if(temp.size() == digits.size()){
            res.push_back(temp);
            return;
        }

        for(char c: mp[digits[i]]){
            temp += c;
            dfs(i+1, digits, temp, res, mp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string>mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        vector<string> res;
        string temp = "";
        dfs(0, digits, temp, res, mp);
        return res;
    }
};