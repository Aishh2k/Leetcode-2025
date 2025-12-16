class Solution {
public:
    bool isPossible(int k, int h , vector<int>& piles){

        double count = 0;
        for(int i : piles){
            count += ceil((double)i/k);
            if(count>h){
                return false;
            }
        }

        if(count>h){
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
        int mid;
        int res;

        while(low<=high){
            mid = low + (high-low)/2;
            if(isPossible(mid,h,piles)){
                res= mid;
                high = mid-1;;
            }else{
                low = mid+1;
            }
        }

        return res;
        

        
    }
};