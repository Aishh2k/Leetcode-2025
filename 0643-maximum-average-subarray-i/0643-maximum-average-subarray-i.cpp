class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long sum = 0;
        for(int i = 0;i<k;i++){ // first window
            sum += nums[i];
        }

        double ans = (double)sum/k;
        int l = 1;
        int r = k;

        while(r<nums.size()){ // subsequent windows
            sum = sum + nums[r];
            sum = sum - nums[l-1];
            ans = max(ans, (double)sum/k);
            l++;
            r++;
        }
        return ans;
    }
};