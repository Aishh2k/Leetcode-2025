class Solution {
public:
    int sumD(int n ){
        int sum = 0;
        int d;

        while(n!=0){
            d = n%10;
            n = n/10;
            sum += d*d;
        }

        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> r;
        int d = 0;
        int sum = 0;

        while(n!=1){
            r.insert(n);
            n = sumD(n);
            if(r.count(n)){
                break;
            }
        }

        if(n==1){
            return true;
        }else{
            return false;
        }
        
    }
};
