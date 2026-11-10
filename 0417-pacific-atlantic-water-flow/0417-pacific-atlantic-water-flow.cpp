class Solution {
public:
    void dfs(int i , int j, vector<vector<bool>>& grid, int dist, const vector<vector<int>>& heights){
        if(i<0 || j <0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] || heights[i][j] < dist){
            return;
        }

        grid[i][j] = true;
        dfs(i+1,j, grid, heights[i][j], heights);
        dfs(i,j+1, grid, heights[i][j], heights);
        dfs(i-1,j, grid, heights[i][j], heights);
        dfs(i,j-1, grid, heights[i][j], heights);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pa(m,vector<bool>(n,false));
        vector<vector<bool>> at(m,vector<bool>(n,false));

        for(int j = 0;j<n;j++){
            dfs(0, j, pa, 0, heights);
            dfs(m-1, j, at, 0, heights);
        }

        for(int i = 0;i<m;i++){
            dfs(i,0, pa, 0, heights);
            dfs(i, n-1, at, 0, heights);
        }

        vector<vector<int>> res;

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(at[i][j] && pa[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res; 
    }
};