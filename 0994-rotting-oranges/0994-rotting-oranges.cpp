class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        int fresh = 0;
        queue<pair<int, int>> rotten;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    rotten.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        while (!rotten.empty() && fresh > 0) {
            int s = rotten.size();
            time++;

            for (int i = 0; i < s; i++) {
                auto [r, c] = rotten.front();
                rotten.pop();

                vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

                for (auto [dr, dc] : dir) {
                    dr += r;
                    dc += c;

                    if (dr < grid.size() && dc < grid[0].size() && dr >= 0 &&
                        dc >= 0 && grid[dr][dc] == 1) {
                        fresh--;
                        grid[dr][dc] = 2;
                        rotten.push({dr, dc});
                    }
                }
            }
        }

        if(fresh>0){
            return -1;
        }else{
            return time;
        }
    }
};