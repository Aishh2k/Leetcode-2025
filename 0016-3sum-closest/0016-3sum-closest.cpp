class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int l,r;
        int ans_sum = 0;
        int ans_abs = INT_MAX;
        for(int i =0;i<nums.size();i++){
            if(i>0 && nums[i-1] == nums[i]){
                continue;
            }
            l =i+1;
            r = nums.size()-1;
            while(l<r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == target){
                    return sum;
                }else{
                    int ab = abs(target-sum);
                    if(ab<ans_abs){
                        ans_abs = ab;
                        ans_sum = sum;
                    }
                    if(sum>target){
                        r--;
                    }else{
                        l++;
                    }
                }
            }
        }
        return ans_sum;
    }
};