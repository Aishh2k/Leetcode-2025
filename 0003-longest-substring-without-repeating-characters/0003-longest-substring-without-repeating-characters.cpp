class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if(!s.size()){
            return 0;
        }
        
        int l =0;
        int count = 0;
        int n = s.size();
        unordered_set<char> cset;

        for(int r =0;r<n;r++){
            while(cset.find(s[r]) != cset.end()){
                cset.erase(s[l]);
                l++;
            }
            cset.insert(s[r]);

            if(count < cset.size()){
                count = cset.size();
            }

        }

        return count;
        
    }
};
