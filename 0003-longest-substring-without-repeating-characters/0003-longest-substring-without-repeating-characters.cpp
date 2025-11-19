#include <algorithm>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_count = 0;
        int count = 0;
        unordered_set<int> st;
        int i =0;
        

        while(i<s.size()){
            st.clear();
            st.insert(s[i]);
            int j =i+1;
            while(j<s.size() && st.count(s[j]) ==0){
                st.insert(s[j]);
                j++;
            }

            max_count = max(max_count, (int)st.size());
            i++;
        }


        return(max_count);


        
    }
};