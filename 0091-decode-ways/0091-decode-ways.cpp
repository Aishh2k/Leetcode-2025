class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+1, 0);
        dp[0] = 1;
        
        for(int i = 0;i<s.size();i++){
            if(s[i] != '0'){
                dp[i+1] += dp[i];
            }

            if(i>0){
                int two = stoi(s.substr(i-1, 2));
                if(two <= 26  && two >=10){
                    dp[i+1] += dp[i-1];
                }
            }
        }

        return dp[s.size()];
        
    }
};