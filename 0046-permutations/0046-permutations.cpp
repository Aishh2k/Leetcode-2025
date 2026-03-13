class Solution {
public:
    vector<vector<int>> result;
    void dfs(vector<int> nums, vector<int> res, unordered_set<int> st) {
        if (res.size() == nums.size()) {
            result.push_back(res);
            return;
        }

        for (int i : nums) {
            if(!st.count(i)){
                res.push_back(i);
                st.insert(i);
                dfs(nums, res,st);
                st.erase(i);
                res.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> res;
        unordered_set<int> st(nums.begin(), nums.end());

        dfs(nums, res, {});
        return result;
    }
};