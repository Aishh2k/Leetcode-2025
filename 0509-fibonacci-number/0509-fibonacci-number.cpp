class Solution {
public:
    int fib(int n) {
        if(n<=1){
            return n;
        }
        
        vector<int> fi(n+1,0);
        fi[1] = 1;

        for(int i =2;i<=n;i++){
            fi[i] = fi[i-1] + fi[i-2];
        }

        return fi[n];
        
    }
};