class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2){
            return 0;
        }

        int profit = 0;
        int l =0;
        int r = 1;

        while(r<prices.size()){
            if(prices[r]>prices[l]){
                profit = max(profit, prices[r]-prices[l]);
            }else{
                l = r;
            }
            r++;
        }

        return profit;


        
    }
};