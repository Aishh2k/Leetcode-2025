class Solution {
public:
    void dfs(int i, vector<vector<int>>& isConnected, vector<bool>& visited){
        if(visited[i]){
            return;
        }
        visited[i] = true;
        for(int j =0;j<isConnected.size();j++){
            if(isConnected[i][j] == 1 && !visited[j]){
                dfs(j, isConnected, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        vector<bool> visited(isConnected.size(), false);

        for(int i = 0;i< isConnected.size();i++){
            if(!visited[i]){
                count++;
                dfs(i, isConnected, visited);
            }
        }
        return count;
    }
};