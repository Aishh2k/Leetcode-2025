class Solution {
public:
    void dfs(int i , int j , int prevHeight, vector<vector<bool>>& vis, vector<vector<int>>& heights){
        if(i<0 || j<0 || i>= heights.size() || j >= heights[0].size() || heights[i][j] < prevHeight || vis[i][j] != false){
            return;
        }

        vis[i][j] = true;

        dfs(i+1, j, heights[i][j], vis, heights);
        dfs(i, j+1, heights[i][j], vis, heights);
        dfs(i-1, j, heights[i][j], vis, heights);
        dfs(i, j-1, heights[i][j], vis, heights);

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> ans;
        vector<vector<bool>> atl(m, vector<bool>(n, false));
        vector<vector<bool>> pac(m, vector<bool>(n, false));


        for(int i = 0;i<m;i++){
            dfs(i,0, 0, pac, heights);
            dfs(i, n-1, 0, atl, heights);
        }

        for(int j = 0;j<n;j++){
            dfs(0, j, 0, pac, heights);
            dfs(m-1, j, 0, atl, heights);
        }

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(atl[i][j] && pac[i][j]){
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};