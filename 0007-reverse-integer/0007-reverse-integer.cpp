class Solution {
public:
    int reverse(int x) {

        int rev = 0;
        if(x >= INT_MAX || x <= INT_MIN){
                return 0;
        }
        int temp = abs(x);
        while (temp) {
            if(rev > INT_MAX/10){
                return 0;
            }
            rev = rev * 10 + temp % 10;
            temp = temp / 10;
        }

        if (x < 0) {
            rev = rev * -1;
        }

        return rev;
    }
};