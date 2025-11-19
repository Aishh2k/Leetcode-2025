class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        if(strs.size()<=1){
            return {strs};
        }
        unordered_map<string,vector<string>> mp;

        for(string str: strs){
            vector<int> count(26,0);
            for(char i: str){
                count[i-'a']++;
            }

            string key = "";
            for(int i : count){
                key = key+ "," + to_string(i);
            }

            mp[key].push_back(str);
        }

        vector<vector<string>> res;
        for(auto i: mp){
            res.push_back(i.second);
        }

        return(res);
        
    }
};