class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string s: strs){
            vector<int> count(26,0);
            for(char c: s){
                count[c-'a']++;
            }

            string res = "";

            for(int i =0;i<26;i++){
                res += to_string(count[i]) + "*";
            }
            mp[res].push_back(s);
        }

        vector<vector<string>> res;
        for(auto a: mp){
            res.push_back(a.second);
        }

        return res;
        
    }
};