class Solution {
public:
    string reverseWords(string s) {
        vector<string> res;
        for(int i =0;i<s.size();i++){
            if(s[i]!=' '){
                string st = "";
                while(i<s.size() && s[i] != ' '){
                    st += s[i];
                    i++;
                }
                res.push_back(st);
            }
        }

        string ans = "";
        for(int i = res.size()-1;i>=0;i--){
            ans = ans + res[i];
            ans += " ";
        }

        return(ans.substr(0,ans.size()-1));
        
    }
};