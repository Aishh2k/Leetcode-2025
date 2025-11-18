class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string a = strs[0];
        string b = strs[strs.size()-1];

        int i =0;
        string res = "";
        while(i<a.size()){
            if(a[i]==b[i]){
                res+=a[i];
                i++;
            }else{
                break;
            }
        }

        return(res);        
    }
};