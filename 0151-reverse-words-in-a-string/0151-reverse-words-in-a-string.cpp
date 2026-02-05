class Solution {
public:
    string reverseWords(string s) {
        string ans = "";

        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                int r = i;
                while (r >= 0 && s[r] != ' ') {
                    r--;
                }

                ans += s.substr(r+1, i - r);
                ans += ' ';
                i = r+1;
            }
        }

        if(!ans.empty()){
            ans.pop_back();
            return ans;
        }

        return ans;
    }
};