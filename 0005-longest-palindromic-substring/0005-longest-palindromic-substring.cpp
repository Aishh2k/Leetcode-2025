class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<2){
            return s;
        }

        string res = "";
        int count = 0;

        for(int i =0;i<s.size();i++){
            //even
            int l = i;
            int r = i+1;

            while(l>=0 && r<s.size() && s[l] == s[r] ){
                if(r-l+1 > count){
                    count = r-l+1;
                    res = s.substr(l, r-l+1);
                }
                l--;
                r++;
            }

            //odd 
            l = i-1;
            r = i+1;

            while(l>=0 && r<s.size() && s[l] == s[r]){
                if(r-l+1 > count){
                    count = r-l+1;
                    res = s.substr(l, r-l+1);
                }
                l--;
                r++;
            }
        }

        if(res.size() == 0){
            res += s[0];
        }
        
        return res;
        
    }
};