class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fresh = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int m = 0;

        while (!q.empty() && fresh > 0) {
            int size = q.size();
            m++;

            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();

                for (auto d : dir) {
                    int rd = r + d[0];
                    int cd = c + d[1];

                    if (rd >= 0 && rd < grid.size() && cd >= 0 &&
                        cd < grid[0].size() && grid[rd][cd] == 1) {
                        grid[rd][cd] = 2;
                        fresh--;
                        q.push({rd, cd});
                    }
                }
            }
        }

        if (fresh > 0) {
            return -1;
        } else {
            return m;
        }
    }
};