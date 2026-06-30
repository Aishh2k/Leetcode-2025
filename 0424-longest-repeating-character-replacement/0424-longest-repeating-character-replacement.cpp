class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int l = 0;
        int r = 0;
        int ans = 0;

        while(l<s.size()){
            mp[s[l]]++;
            int maxf = 0;

            for(auto i: mp){
                maxf = max(maxf, i.second);
            }

            if(l-r+1 - maxf >k){
                mp[s[r]]--;
                r++;
            }
            ans = max(ans, l-r+1);
            l++;
        }

        return ans;
        
    }
};