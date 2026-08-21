class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;
        int ans = 0;
        while(r < prices.size()){
            if(prices[r] > prices[l]){
                ans = max(ans, prices[r] - prices[l]);
            }else{
                l = r;
            }
            r++;
        }
        return ans;
    }
};