class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map <char, int> count;
        int res = 0;
        int f = 0;
        int l =0;

        for(int r = 0;r<n;r++){
            count[s[r]]++;
            for(auto o: count){
                f = max(f, o.second);
            }
            if(((r-l +1) - f )>k){
                count[s[l]] -=1;
                l++;
            }

            res = max(res, r-l+1);
        }

        return res;
        
    }
};