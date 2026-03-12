class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;

        long long mid = 0;
        int res = 0;

        while(low<=high){
            mid = low + (high-low)/2;
            if(mid*mid == x){
                return mid;
            }else if(mid*mid>x){
                high  = mid-1;
            }else{
                res = mid;
                low = mid+1;
            }
        }

        return res;
        
    }
};