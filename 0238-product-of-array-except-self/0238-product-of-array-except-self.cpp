class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        vector<int>right(n);
        vector<int> left(n);

        left[0]= 1;
        for(int i =1;i<n;i++){
            left[i] = left[i-1]*nums[i-1];
        }
        
        right[n-1]= 1;
        for(int i = n-2;i>=0;i--){
            right[i] = right[i+1]* nums[i+1];
        }

        for(int i =0;i<nums.size();i++){
            res.push_back(right[i]*left[i]);
        }

        return(res);

        
    }
};

/*

n = 4
0 1 2 3
a b c d

left = 1 a ab abc
right =  bcd cd d 1

bcd acd abd abc
a.  b.  c.  d.



*/