class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int ans = 0;
        unordered_map<char, int> mp;

        while(r<s.size()){
            mp[s[r]]++;
            int maxf = 0;
            for(auto p: mp){
                if(p.second>maxf){
                    maxf = p.second;
                }
            }

            while(r-l+1 - maxf > k ){
                mp[s[l]]--;
                l++;
            }
            ans = max(ans, r-l+1);
            r++;
        }

        return ans;
    }
};