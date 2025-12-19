class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int l = 0;
        int max_count = 0;
        if (s.size() == 0) {
            return 0;
        }

        if (s.size() < 2) {
            return 1;
        }

        for (int r = 0; r < s.size(); r++) {
            if (!st.count(s[r])) {
                st.insert(s[r]);
            } else {
                while (st.count(s[r]) && l < r) {
                    st.erase(s[l]);
                    l++;
                }
                st.insert(s[r]);
            }
            max_count = max(max_count, r - l + 1);
        }
        return max_count;
    }
};