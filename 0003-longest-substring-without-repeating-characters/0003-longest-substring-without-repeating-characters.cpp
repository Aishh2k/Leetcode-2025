class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int res = 0;
        int r = 0;

        for(int l =0;l<s.size();l++){
            while(st.count(s[l])){
                st.erase(s[r]);
                r++;
            }

            st.insert(s[l]);
            res = max(res, l-r+1);
        }

        return res;
        
    }
};