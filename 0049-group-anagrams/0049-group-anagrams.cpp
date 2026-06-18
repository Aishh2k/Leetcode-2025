class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string s: strs){
            vector<int> count(26,0);
            for(char c: s){
                count[c-'a']++;
            }
            string k = "";
            for(int i = 0;i<26;i++){
                k += to_string(count[i]) + "*";
            }
            mp[k].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto i: mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};