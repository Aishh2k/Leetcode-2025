class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sCount(26, 0);
        vector<int> tCount(26,0);

        for(int i =0;i<s.size();i++){
            sCount[s[i]-'a']++;
        }

        for(int i=0;i<t.size();i++){
            tCount[t[i]-'a']++;
        }

        if(sCount==tCount){
            return true;
        }else{
            return false;
        }
        
    }
};