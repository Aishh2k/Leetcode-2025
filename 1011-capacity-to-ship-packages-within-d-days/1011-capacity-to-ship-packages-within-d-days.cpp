class Solution {
public:
    bool isPossible(vector<int>& weights, int days, int capacity){
        int d = 1;
        int total = 0;
        for(int i =0;i<weights.size();i++){
            if(total + weights[i] <= capacity){
                total += weights[i];
            }else{
                total = weights[i];
                d++;
            }
        }
        if(d<=days){
            return true;
        }else{
            return false;
        }
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0;
        int high = 0;
        int res = 0;
        int mid;

        for(int i : weights){
            high += i;
            low = max(low,i);
        }

        while(low<=high){
            mid = low + (high-low)/2;

            if(isPossible(weights, days, mid)){
                res = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        return res;
        
    }
};