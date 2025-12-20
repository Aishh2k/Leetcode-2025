class Solution {
public:
    int characterReplacement(string s, int k) {
        int max_len = 0;
        unordered_map<char, int> mp;
        int l =0;

        for(auto r =0;r<s.size();r++){
            mp[s[r]]++;
            int maxf = 0;
            for(auto m : mp){
                maxf = max(maxf, m.second);
            }

            while((r-l+1) - maxf >k){
                mp[s[l]]--;
                l++;
            }
            max_len = max(max_len,r-l+1);
        }

        return max_len;
    }
};