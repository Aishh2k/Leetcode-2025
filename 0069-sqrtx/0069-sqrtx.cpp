class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) {
            return x;
        }
        int l = 0;
        int r = x;
        int mid = 0;
        int ans = 0;

        while (l <= r) {
            mid = l + (r - l) / 2;
            long long res = (long long)mid * mid;
            if (res == x) {
                return mid;
            } else if (res > x) {
                r = mid-1;
            } else {
                ans = mid;
                l = mid + 1;
            }
        }
        return ans;
    }
};