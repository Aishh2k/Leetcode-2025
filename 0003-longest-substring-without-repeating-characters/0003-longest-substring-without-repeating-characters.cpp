class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> last; // char -> last index
        int L = 0, best = 0;

        for (int R = 0; R < (int)s.size(); R++) {
            char c = s[R];

            if (last.count(c) && last[c] >= L) {
                L = last[c] + 1;   // jump left past the previous c
            }

            last[c] = R;
            best = max(best, R - L + 1);
        }
        return best;
    }
};
