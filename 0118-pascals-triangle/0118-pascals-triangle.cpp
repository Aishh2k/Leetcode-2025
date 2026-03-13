class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==1){
            return {{1}};
        }else if(numRows ==2){
            return {{1},{1,1}};
        }

        vector<vector<int>> res;
        res.push_back({1});
        res.push_back({1,1});

        for(int i = 2;i<numRows;i++){
            vector<int> prev = res[i-1];
            vector<int> next;

            next.push_back(1);
            for(int j =1;j<i;j++){
                next.push_back(prev[j-1] + prev[j]);
            }
            next.push_back(1);
            res.push_back(next);
        }

        return res;
        
    }
};