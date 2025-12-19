class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int maxf = 0;
        int res = 0;

        unordered_map<char, int> mp;

        for (int r = 0; r < s.size(); r++) {
            mp[s[r]]++;
            maxf = 0;
            for (auto m : mp) {
                maxf = max(maxf, m.second);
            }

            while ((r - l + 1) - maxf > k) {
                mp[s[l]]--;
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};