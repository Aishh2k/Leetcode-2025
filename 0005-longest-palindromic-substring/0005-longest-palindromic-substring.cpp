class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<=1){
            return s;
        }
        int len = 1;
        string ans = s.substr(0, 1);

        for(int i = 1;i<s.size();i++){
            // odd length 
            int r = i+1;
            int l = i-1;

            while(l>=0 && r< s.size() && s[r] == s[l]){
                if(r-l+1 > len){
                    len = r-l+1;
                    ans = s.substr(l,len);
                }
                r++;
                l--;
            }

            //even length
            r = i;
            l = i-1;
            while(l>=0 && r<s.size() && s[r] == s[l]){
                if(r-l+1 > len){
                    len = r-l+1;
                    ans = s.substr(l,len);
                }
                r++;
                l--;
            }
        }

        return ans;
        
    }
};