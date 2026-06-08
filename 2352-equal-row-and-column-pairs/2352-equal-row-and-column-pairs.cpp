class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> mp;
        int ans = 0;

        for(auto i: grid){
            mp[i]++;
        }

        for(int i = 0 ;i<grid.size();i++){
            vector<int> col;
            for(int j =0;j<grid.size();j++){
                col.push_back(grid[j][i]);
            }

            ans += mp[col];
        }
        
        return ans;
    }
};