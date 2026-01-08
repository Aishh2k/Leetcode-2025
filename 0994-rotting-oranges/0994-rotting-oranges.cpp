class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fresh = 0;

        for(int i =0;i<grid.size();i++){
            for(int j =0;j<grid[0].size();j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                } else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        int min = 0;
        vector<pair<int, int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};

        while(q.size()>0 && fresh>0){
            int size = q.size();

            for(int i = 0;i<size;i++){
                auto [r,c] = q.front();
                q.pop();

                for(auto [dr,dc] : dir){
                    dr += r;
                    dc += c;

                    if(dr >=0 && dc >=0 && dr< grid.size() && dc< grid[0].size()){
                        if(grid[dr][dc] == 1){
                            grid[dr][dc] = 2;
                            q.push({dr,dc});
                            fresh--;
                        }
                    }
                }
            }
            min++;
        }

        if(fresh > 0 ){
            return -1;
        }else{
            return min;
        }
        
    }
};