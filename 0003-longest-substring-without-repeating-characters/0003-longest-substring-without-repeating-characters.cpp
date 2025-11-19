class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int count = 0;
        int max_count = 0;
        unordered_set<char> c;

        for(int r =0;r<s.size();r++){
            while(c.count(s[r])){
                c.erase(s[l]);
                l++;
            }
            c.insert(s[r]);
            count = c.size();
            max_count = max(count, max_count);
        }


        return(max_count);
        
    }
};