class Solution {
public:
    string longestPalindrome(string s) {
        int r = 0;
        int l = 0;
        string res = "";
        int count = 0;

        for(int i =0;i<s.size();i++){
            // odd length palindrome string
            r = i;
            l = i;

            while(r < s.size() && l>=0 && s[r] == s[l]){
                if(r-l+1 >count){
                    count = r-l+1;
                    res = s.substr(l, count);
                }
                r++;
                l--;
            }

            // even
            l = i;
            r = i+1;

            while(r< s.size() && l>=0 && s[r] == s[l]){
                if(r-l+1 >count){
                    count = r-l+1;
                    res = s.substr(l, count);
                }
                r++;
                l--;
            }

        }

        return res;
        
    }
};