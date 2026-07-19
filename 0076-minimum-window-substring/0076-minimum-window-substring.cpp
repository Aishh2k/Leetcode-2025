class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) {
            return "";
        }

        unordered_map<char, int> mp;
        for (char c : t) {
            mp[c]++;
        }

        int l = 0;
        int r = 0;
        int req = t.size();
        int ans = INT_MAX;
        int ans_start = 0;

        while (r < s.size()) {
            char c = s[r];
            if (mp[c] > 0) {
                req--;
            }
            mp[c]--;

            while (req == 0) {
                if (r - l + 1 < ans) {
                    ans = r - l + 1;
                    ans_start = l;
                }
                mp[s[l]]++;
                if (mp[s[l]] > 0) {
                    req++;
                }
                l++;
            }
            r++;
        }
        if(ans == INT_MAX) return "";
        
        return s.substr(ans_start, ans);
    }
};