class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long int prevMaxOdd = 0, prevMaxEven = 0, temp;
        int n = nums.size();
        prevMaxOdd = nums[0];
        
        for(int i = 1; i < n ; i++){
            temp = prevMaxOdd;           
            prevMaxOdd = max(prevMaxOdd, prevMaxEven + nums[i]);           
            prevMaxEven = max(prevMaxEven, temp - nums[i]);          
        }
        
        return (prevMaxOdd);  
    }
};