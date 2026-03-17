class Solution {
public:
    void dfs(int i, vector<vector<int>>&c, unordered_set<int>& visited){
        visited.insert(i);

        for(int j =0;j<c[0].size();j++){
            if(j==i){
                continue;
            }
            if(!visited.count(j) && c[i][j] ==1){
                dfs(j,c,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& c) {
        unordered_set<int> visited;
        int res = 0;

        for(int i =0; i<c.size();i++){
            if(!visited.count(i)){
                res++;
                dfs(i,c,visited);
            }
        }

        return res;
        
    }
};