class Solution {
public:
    int res = 0;
    void dfs( vector<int>& count){

        for(int i =0;i<26;i++){
            if(count[i] > 0){
                count[i]--;
                res++;
                dfs(count);
                count[i]++;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        vector<int> count(26,0);
        for(auto c: tiles){
            count[c-'A']++;
        }

        dfs(count);
        return res;
        
    }
};