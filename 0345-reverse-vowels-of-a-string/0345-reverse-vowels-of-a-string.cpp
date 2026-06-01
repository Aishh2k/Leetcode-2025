class Solution {
public:
    bool isVowel(char a) {
        char c = tolower(a);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            while (l < r && !isVowel(s[l])) {
                l++;
            }
            while (l < r && !isVowel(s[r])) {
                r--;
            }
            swap(s[l], s[r]);
            r--;
            l++;
        }
        return s;
    }
};