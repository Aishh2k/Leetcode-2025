class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> total_amount(amount+1, INT_MAX);
        total_amount[0]=0;

        for(int i =1;i<=amount;i++){
            for(int coin : coins){
                if(!(coin>i) && total_amount[i-coin] != INT_MAX){
                    total_amount[i] = min(total_amount[i-coin]+1,total_amount[i]);
                }
            }
        }

        if(total_amount[amount] == INT_MAX){return -1;}

        return(total_amount[amount]);

    }
};