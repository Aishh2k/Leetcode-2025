class Solution {
public:
    void dfs(int i,int j, int& area, vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] != 1){
            return;
        }

        grid[i][j] = 0;
        area++;
        
        dfs(i+1,j,area, grid);
        dfs(i,j+1,area, grid);
        dfs(i-1,j,area,grid);
        dfs(i,j-1,area,grid);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for(int i =0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    int area = 0;
                    dfs(i,j,area, grid);
                    res = max(res,area);
                }
            }
        }

        return res;
        
    }
};