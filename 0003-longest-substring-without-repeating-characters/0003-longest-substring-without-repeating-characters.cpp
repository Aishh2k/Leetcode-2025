class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int count = 0;
        int l = 0;

        for(int r =0;r<s.size();r++){
            while(st.find(s[r]) != st.end()){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            count = max(count, r-l+1);
        }

        return count;
        
    }
};