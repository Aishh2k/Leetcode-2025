class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit = 0;
        int max_profit = 0;
        int l =0;

        for(int r =1;r<prices.size();r++){
            if(prices[r]>prices[l]){
                profit = prices[r]- prices[l];
                max_profit = max(max_profit, profit);
            }else{
                l =r;
            }

        }

        return max_profit;

        
    }
};