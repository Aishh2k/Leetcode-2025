class Solution {
public:
    bool isPossible(int speed, vector<int>& piles, int h){
        double hrs = 0;
        for(int i : piles){
            hrs += ceil((double)i/speed);
        }
        if(hrs>h){
            return false;
        }else{
            return true;
        }
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 0;
        for(int i: piles){
            high = max(high, i);
        }

        int res;
        int mid;

        while(low<=high){
            mid = low + (high-low)/2;
            if(isPossible(mid, piles, h)){
                res = mid;
                high = mid -1;
            }else{
                low = mid+1;
            }
        }

        return res;
    }
};