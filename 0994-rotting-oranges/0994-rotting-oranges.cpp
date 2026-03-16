class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fresh = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push(make_pair(i, j));
                }else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        int t = 0;
        vector<pair<int, int>> d = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        while (!q.empty() && fresh>0) {
            int size = q.size();
            t++;
            for (int i = 0; i < size; i++) {
                pair<int, int> rot = q.front();
                q.pop();

                for (auto [dr, dc] : d) {
                    dr += rot.first;
                    dc += rot.second;

                    while (dr >= 0 && dc >= 0 && dr < grid.size() &&
                           dc < grid[0].size() && grid[dr][dc] == 1) {

                        q.push({dr, dc});
                        grid[dr][dc] = 2;
                        fresh--;
                    }
                }
            }
        }

        if(fresh>0){
            return -1;
        }

        return t;
    }
};