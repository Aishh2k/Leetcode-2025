class Solution {
public:
    int countBinarySubstrings(string s) {
        int cur = 1;
        int ans = 0;
        int prev = 0;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                cur++;
            } else {
                prev = cur;
                cur = 1;
            }

            if (prev >= cur) {
                ans++;
            }
        }

        return ans;
    }
};
