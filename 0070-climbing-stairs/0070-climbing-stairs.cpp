class Solution {
public:
    int climbStairs(int n) {
        if(n==1){
            return 1;
        }else if (n==2){
            return 2;
        }

        vector<int> cost(n+1,0);
        cost[1] =1;
        cost[2]=2;

        for(int i =3;i<=n;i++){
            cost[i] = cost[i-1]+ cost[i-2];
        }

        return cost[n];
        
    }
};