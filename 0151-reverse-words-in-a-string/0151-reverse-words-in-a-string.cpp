class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        vector<string> vs;
        int i =0;

        while(i<s.size()){
            while(i<s.size() && s[i] == ' '){
                i++;
            }

            if(i==s.size()){
                break;
            }

            int l = i;
            while(i<s.size() && s[i] != ' '){
                i++;
            }
            
            string a = s.substr(l, i-l);
            vs.push_back(a);
        }


        for(int i =vs.size()-1;i>0;i--){
            ans += vs[i];
            ans += " ";
        }

        ans += vs[0];
        return ans;
        
    }
};