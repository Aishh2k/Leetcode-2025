class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> countS (26,0);
        vector<int> countT (26,0);

        for(int i = 0;i <s.size();i++){
            countS[s[i] -'a']++;
        }

        for(int i = 0;i <t.size();i++){
            countT[t[i] -'a']++;
        }

        if(countS == countT){
            return true;
        }else{
            return false;
        }
        
    }
};