class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size()){
            return "";
        }

        unordered_map<char,int> mp;
        for(char c: t){
            mp[c]++;
        }
        int l = 0;
        int ans_len = INT_MAX;
        int ans_start = 0;
        int req = t.size();

        for(int r = 0;r<s.size();r++){
            if(mp[s[r]]>0){
                req--;
            }
            mp[s[r]]--;

            while(req == 0){
                if(r-l+1 < ans_len){
                    ans_len = r-l+1;
                    ans_start = l;
                }

                mp[s[l]]++;
                if(mp[s[l]]>0){
                    req++;
                }
                l++;
            }
        }

        if(ans_len == INT_MAX){
            return "";
        }else{
            return s.substr(ans_start, ans_len);
        }
        
    }
};
