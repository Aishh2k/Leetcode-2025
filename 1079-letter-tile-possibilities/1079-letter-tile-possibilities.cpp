class Solution {
public:
    int ans = 0;
    void dfs(unordered_map<char, int>&mp){
        for(auto i: mp){
            if(i.second > 0){
                ans++;
                mp[i.first]--;
                dfs(mp);
                mp[i.first]++;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> mp;
        for(char c: tiles){
            mp[c]++;
        }
        dfs(mp);
        return ans;
    }
};