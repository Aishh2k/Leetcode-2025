class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0;
        int l = 0;
        int r = 0;
        while(l<=nums.size()-1){
            r = nums[l] + l;
            int far = 0;
            for(int i =l;i<=r;i++){
                far = max(far, nums[i] +i);
            }
            l = r+1;
            r = far;
            res++;
        }

        return res;
        
    }
};