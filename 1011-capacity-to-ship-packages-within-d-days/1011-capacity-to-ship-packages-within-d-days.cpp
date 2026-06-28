class Solution {
public:
    bool isPossible(int mid, vector<int>& weights, int days){
        int count = 1;
        int sum = 0;

        for(int i : weights){
            sum += i;
            if(sum>mid){
                sum = i;
                count++;
                if(count>days){
                    return false;
                }
            }
        }
        if(count>days) return false;
        else return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = 0;
        int res = 0;
        int mid = 0;

        for (int i : weights) {
            high += i;
        }

        while (low <= high) {
            mid = low + (high - low)/2;
            if(isPossible(mid, weights, days)){
                res = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return res;
    }
};