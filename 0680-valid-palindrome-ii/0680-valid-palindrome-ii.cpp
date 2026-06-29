class Solution {
public:
    bool isPal(int l , int r, string s){
        while(l<=r){
            if(s[l] == s[r]){
                l++;
                r--;
            }else{
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.size()-1;

        while(l<=r){
            if(s[l] == s[r]){
                r--;
                l++;
            }else{
                return (isPal(l+1, r, s) || isPal(l, r-1, s));
            }
        }
        return true;
    }
};