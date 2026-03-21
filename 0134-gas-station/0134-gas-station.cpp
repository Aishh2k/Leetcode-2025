class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int sum = 0;
        int idx = 0;

        for (int i = 0; i < cost.size(); i++) {
            sum += gas[i] - cost[i];
            total += gas[i] - cost[i];

            if(sum<0){
                sum = 0;
                idx = i+1;
            }
        }

        if(total<0){
            return -1;
        }
        return idx;
    }
};