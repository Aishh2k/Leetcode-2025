class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        int res;
        long long mid;

        if(x<=1){
            return x;
        }


        while(low<=high){
            mid = low + (high-low)/2;
            if(mid*mid <= x){
                res = mid;
                low = mid+1;
            }else if(mid*mid > x){
                high = mid-1;
            }
        }

        return res;
    }
};