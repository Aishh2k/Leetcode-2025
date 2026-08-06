class Solution {
public:
    void dfs(int n, vector<vector<int>>& res, vector<int>& temp, unordered_map<int, int>&mp){
        if(temp.size() == n){
            res.push_back(temp);
            return;
        }

        for(auto p: mp){
            if(p.second > 0){
                mp[p.first]--;
                temp.push_back(p.first);
                dfs(n, res, temp, mp);
                mp[p.first]++;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int>mp;
        vector<vector<int>> res;
        vector<int> temp;

        for(auto i: nums){
            mp[i]++;
        }

        dfs(nums.size(), res, temp, mp);
        return res;
        
    }
};