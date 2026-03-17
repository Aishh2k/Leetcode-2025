class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> coinCount(amount+1);

        coinCount[0] = 0;

        for(int i =1;i<=amount;i++){
            coinCount[i] = INT_MAX;

            for(int coin: coins){
                if(coin<=i && coinCount[i-coin] != INT_MAX){
                    coinCount[i] = min(coinCount[i], 1+coinCount[i-coin]);
                }
            }
        }
        
        if(coinCount[amount] == INT_MAX){
            return -1;
        }
        return(coinCount[amount]);
        
    }
};