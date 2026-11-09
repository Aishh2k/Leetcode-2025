class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(int i = 0;i<s.size();i++){
            if(isalnum(s[i])){
                str += tolower(s[i]);
            }
        }

        cout<<str;
        for(int i = 0;i<str.size()/2;i++){
            if(str[i] != str[str.size()-1-i]){
                return false;
            }
        }

        return true;
        
    }
};