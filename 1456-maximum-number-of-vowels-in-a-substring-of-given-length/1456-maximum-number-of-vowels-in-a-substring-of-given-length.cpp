class Solution {
public:
    bool isVowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            return true;
        }
        return false;
    }

    int maxVowels(string s, int k) {
        int count = 0;
        int maxCount = 0;

        int r = 0;
        int l = 0;

        while(r<k){
            if(isVowel(s[r])){
                count++;
            }
            r++;
        }

        maxCount = count;

        while(r<s.size()){
            if(isVowel(s[l])){
                count--;
            }
            l++;
            if(isVowel(s[r])){
                count++;
            }
            r++;

            maxCount = max(maxCount, count);
        }

        return maxCount;
        
    }
};