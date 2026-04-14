class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int cur_sum = 0;
        int min_sum = 0;

        for(int i =0;i<nums.size();i++){
            cur_sum += nums[i];

            if(cur_sum<min_sum){
                min_sum = cur_sum;
            }
        }

        return (1-min_sum);
    }
};