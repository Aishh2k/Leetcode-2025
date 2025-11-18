class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size()-1;
        int j=0;
        
        while(i >=0 && s[i]== ' '){
            i--; // remove extra space if any
        }
        
        while(i>=0 && s[i] != ' '){
            j++;
            i--;
        }


        return j;
    }
};