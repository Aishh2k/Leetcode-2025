class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> res;
        for( auto s : strs){
            vector<int> c(26,0);
            for( auto a: s){
               c[a-'a']++;
            }
            string key = "";
            for(int i =0;i<c.size();i++){
                key = key + ","+ to_string(c[i]);
            }

            mp[key].push_back(s);

        }

        for(auto a: mp){
            res.push_back(a.second);
        }

        return res;


        
    }
};