class Solution {
public:
    bool isPossible(int mid, int h, vector<int>&piles){
        int count = 0;

        for(int i : piles){
            count += (i+mid-1)/mid;
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
        int high = *max_element(piles.begin(), piles.end());
        int res = 0;

        while(low<=high){
            int mid = low + (high-low)/2;
            if(isPossible(mid, h, piles)){
                res = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        return res;
        
    }
};