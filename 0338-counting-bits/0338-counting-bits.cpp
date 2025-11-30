class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;

        for(int i =0;i<=n;i++){
            int count = 0;
            int n = i;
            while(n>0){
                count += n%2;
                n= n/2;
            }

            res.push_back(count);

        }

        return res;
        
    }
};