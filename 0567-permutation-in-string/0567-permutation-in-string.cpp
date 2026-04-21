class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        if(n1>n2){
            return false;
        }

        vector<int> countS1(26,0);
        vector<int> countS2(26,0);
        for(int i =0;i<n1;i++){
            countS1[s1[i]-'a']++;
            countS2[s2[i]-'a']++;
        }

        if(countS1 == countS2){
            return true;
        }

        for(int i = n1;i<n2;i++){
            countS2[s2[i]-'a']++;
            countS2[s2[i-n1]-'a']--;

            if(countS2 == countS1){
                return true;
            }
        }
        return false;  
    }
};