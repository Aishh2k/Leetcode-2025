class Solution {
public:
    vector<vector<int>> result;
    void backtrack(vector<int> candidates, int target, int i, vector<int> res){
        if(target == 0){
            result.push_back(res);
            return;
        }
        if(target<0){
            return;
        }

        if(i>=candidates.size()){
            return;
        }
        
        res.push_back(candidates[i]);
        backtrack(candidates, target-candidates[i], i, res); // take it
        res.pop_back();
        backtrack(candidates, target, i+1,res); // dont take it

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> res;
        backtrack(candidates, target, 0, res);
        return result;  
    }
};