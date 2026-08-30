class Solution {
public:
    int countSubstrings(string s) {
        if(s.size()<=1){
            return s.size();
        }

        int ans = 1;

        for(int i = 1;i<s.size();i++){
            // odd length
            int r = i;
            int l = i;
            while(l>=0 && r<s.size() && s[r] == s[l]){
                ans++;
                r++;
                l--;
            }

            // even length
            r = i;
            l = i-1;
            while(l>=0 && r<s.size() && s[r] == s[l]){
                ans++;
                r++;
                l--;
            }

        }

        return ans;


        
    }
};