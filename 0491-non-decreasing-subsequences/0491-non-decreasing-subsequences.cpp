class Solution {
public:
    vector<vector<int>> result;
    void dfs(int idx, vector<int>&nums, vector<int>& temp){
        if(temp.size() >= 2){
            result.push_back(temp);
        }
        unordered_set<int> st;
        for(int i =idx; i<nums.size();i++){
            if((temp.empty() || nums[i] >= temp.back()) && (st.find(nums[i]) == st.end())){
                temp.push_back(nums[i]);
                dfs(i+1, nums, temp);
                temp.pop_back();
                st.insert(nums[i]);
            }
        }

    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        dfs(0,nums, temp);
        return result;
    }
};