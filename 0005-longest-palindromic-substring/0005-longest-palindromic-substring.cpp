class Solution {
public:
    string longestPalindrome(string s) {
        int resL = 0;
        string res = "";

        for(int i =0;i<s.size();i++){
            // odd length palindrome
            int l = i;
            int r = i;
            while(r<s.size() && l >=0 && s[r]==s[l]){
                if(r-l +1 > resL){
                    resL = r-l +1;
                    res = s.substr(l, resL);
                }
                l--;
                r++;
            }

            // even length palindrome
            l = i;
            r = i+1;
            while(r<s.size() && l >=0 && s[r]==s[l]){
                if(r-l +1 > resL){
                    resL = r-l +1;
                    res = s.substr(l, resL);
                }
                l--;
                r++;
            }
        }


        return res;
        
    }
};