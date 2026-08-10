class Solution {
public:
    vector<vector<string>> result;
    bool isPalindrome(string s, int start, int end){
        while(start<end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }

        return true;
    }
    void dfs(int idx, string s, vector<string>& temp){
        if(idx >= s.size()){
            result.push_back(temp);
            return;
        }
        string str = "";

        for(int i = idx;i<s.size();i++){
            if(isPalindrome(s, idx, i)){
                temp.push_back(s.substr(idx, i-idx+1));
                dfs(i+1, s, temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        dfs(0, s, temp);
        return result;
    }
};