class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        sort(strs.begin(), strs.end());
        string ans = "";
        string a = strs[0];
        string b = strs[strs.size() - 1];
        int i = 0;

        while (i < a.size() && i<b.size()) {
            if (a[i] == b[i]) {
                ans += a[i];
                i++;
            } else {
                return ans;
            }
        }

        return ans;
    }
};