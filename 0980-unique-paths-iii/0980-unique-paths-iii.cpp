class Solution {
public:
    int res;
    int nonObs;

    void dfs(int r, int c, vector<vector<int>>& grid, int count){
        if(r<0 || c<0 || r>= grid.size()|| c >= grid[0].size() || grid[r][c] == -1){
            return;
        }

        if(grid[r][c] == 2){
            if(count == nonObs){
                res++;
            }
            return;
        }

        grid[r][c] = -1;
        dfs(r+1, c, grid, count+1);
        dfs(r, c+1, grid, count+1);
        dfs(r-1, c, grid, count+1);
        dfs(r, c-1, grid, count+1);
        grid[r][c] = 0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int r =0;
        int c = 0;
        int count = 0;
        nonObs = 1;
        res = 0;

        for(int i =0;i<grid.size();i++){
            for(int j =0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    r = i;
                    c = j;
                }else if(grid[i][j] == 0){
                    nonObs++;
                }
            }
        }

        dfs(r,c,grid, count);
        return res;
    }   
};