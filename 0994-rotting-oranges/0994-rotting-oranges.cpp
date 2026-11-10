class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> rotten;
        int fresh = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    rotten.push(make_pair(i, j));
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int mins = 0;

        while (!rotten.empty() && fresh > 0) {
            int n = rotten.size();
            mins++;
            for (int i = 0; i < n; i++) {
                auto [r, c] = rotten.front();
                rotten.pop();

                for (auto [dr, dc] : dir) {
                    dr += r;
                    dc += c;

                    if (dr >= 0 && dc >= 0 && dr < grid.size() &&
                        dc < grid[0].size() && grid[dr][dc] == 1) {
                        grid[dr][dc] = 2;
                        fresh--;
                        rotten.push(make_pair(dr, dc));
                    }
                }
            }
        }

        if (fresh > 0) {
            return -1;
        } else {
            return mins;
        }
    }
};