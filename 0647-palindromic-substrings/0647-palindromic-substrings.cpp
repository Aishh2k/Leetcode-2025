class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        int r, l;

        for(int i =0;i<s.size();i++){
            // odd
            r = i;
            l = i;

            while(r>=0 && l<s.size() && s[l] == s[r]){
                res++;
                r--;
                l++;
            }

            // even
            r = i;
            l = i+1;

            while(r>=0 && l<s.size() && s[l] == s[r]){
                res++;
                r--;
                l++;
            }
        }

        return res;
    }
};