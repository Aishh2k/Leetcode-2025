class Solution {
public:
    vector<pair<int, int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};

    void dfs(int i , int j, int prev, vector<vector<bool>>& visited, vector<vector<int>>& heights){
        if(i>=heights.size() || j>= heights[0].size() || i<0 || j<0){
            return;
        }

        if(heights[i][j] < prev || visited[i][j]){
            return;
        }

        visited[i][j] = true;

        for(auto [dr, dc]: dir){
            dr += i;
            dc += j;
            dfs(dr,dc,heights[i][j], visited, heights);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> ans;

        vector<vector<bool>> atl(m, vector<bool>(n, false));
        vector<vector<bool>> pac(m, vector<bool>(n, false));

        for(int j=0;j<n;j++){
            dfs(m-1,j,INT_MIN,atl,heights);
            dfs(0, j, INT_MIN,pac, heights);
        }

        for(int i=0;i<m;i++){
            dfs(i,0,INT_MIN,pac,heights);
            dfs(i,n-1,INT_MIN,atl,heights);
        }

        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(atl[i][j] && pac[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};