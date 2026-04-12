class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());

        string s = "";
        int i =0;
        string a = strs[0];
        string b = strs[strs.size()-1];
        while(i<a.size() && i<b.size()){
            if(a[i] == b[i]){
                s += a[i];
                i++;
            }else{
                return s;
            }
        }

        return s;
    }
};