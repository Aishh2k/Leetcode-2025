class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> res(n, 1);
        int ans = 0;

        // left to right
        for(int i =1;i<n;i++){
            if(ratings[i]> ratings[i-1]){
                    res[i] = res[i-1]+1;
            }
        }

        // right to left
        for(int i = ratings.size()-2;i>=0;i--){
            if(ratings[i]> ratings[i+1]){
                    res[i] = max(res[i+1] +1, res[i]);
            }
        }

        for(int i: res){
            ans += i;
        }

        return ans;
        
    }
};