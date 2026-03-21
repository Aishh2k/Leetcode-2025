class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> total;
        int sum = 0;

        for(int i =0;i<cost.size();i++){
            total.push_back(gas[i]-cost[i]);
            sum = sum+total[i];
        }

        if(sum<0){
            return -1;
        }

        sum = 0;
        int idx;

        for(int i =0;i<cost.size();i++){
            sum += total[i];

            if(sum<0){
                idx = i+1;
                sum = 0;
            }
        }

        return idx;


        
    }
};