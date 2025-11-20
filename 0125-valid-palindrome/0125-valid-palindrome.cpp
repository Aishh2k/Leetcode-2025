class Solution {
public:
    bool isPalindrome(string s) {
        string al;
        for(int i=0;i<s.size();i++){
            if(isalnum(s[i])){
                s[i]= tolower(s[i]);
                al+=s[i];
            }
        }
        for(int i=0;i<al.size()/2;i++){
            if(al[i] != al[al.size()-1-i]){
                return(false);
            }
        }
        return(true);
    }
};
