class Solution {
public:
    vector<vector<int>> result;
    void dfs(vector<int> nums,vector<int> res, unordered_set<int> st){
        if(res.size()==nums.size()){
            result.push_back(res);
            return;
        }

        for(int i: st){
            unordered_set<int> next = st;
            res.push_back(i); 
            next.erase(i); 
            dfs(nums,res,next);
            next.insert(i);
            res.pop_back(); 
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> res;
        unordered_set<int> st(nums.begin(), nums.end());

        dfs(nums,res,st);
        return result;
        
    }
};