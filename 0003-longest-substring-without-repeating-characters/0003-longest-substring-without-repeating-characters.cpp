class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int max_count = 0;
        int l =0;

        for(int r =0;r<s.size();r++){

            while(st.find(s[r]) != st.end()){
                st.erase(s[l]);
                l++;
            }

            st.insert(s[r]);
            if(max_count<st.size()){
                max_count = st.size();
            }
            
        }

        return max_count;
        
    }
};