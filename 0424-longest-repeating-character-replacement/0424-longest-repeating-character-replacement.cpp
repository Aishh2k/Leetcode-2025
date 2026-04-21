class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int maxf = 0;
        unordered_map<char,int> mp;
        int res = 0;

        while(r<s.size()){
            mp[s[r]]++;
            maxf = 0;

            for(auto i: mp){
                maxf = max(maxf, i.second);
            }

            if((r-l+1-maxf) > k){
                mp[s[l]]--;
                l++;
            }
            res = max(res, r-l+1);
            r++;

        }

        return res;

        
    }
};