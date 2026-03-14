class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = -1;

        for(int i =nums.size()-2;i>=0;i--){
            if(nums[i] <nums[i+1]){
                pivot = i;
                break;
            }
        }

        if(pivot == -1){
            sort(nums.begin(), nums.end());
            return;
        }

        for(int j =nums.size()-1;j>=0;j--){
            if(nums[j]>nums[pivot]){
                swap(nums[j], nums[pivot]);
                break;
            }
        }

        reverse(nums.begin()+pivot+1, nums.end());
        return;

        
    }
};