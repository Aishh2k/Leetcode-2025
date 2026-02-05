class Solution {
public:

    void reverseArray(vector<int>& nums, int l ,int r){
        while(l<r){
            swap(nums[l], nums[r]);
            l++;r--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        if(nums.size()<=1){
            return;
        }

        k = k%nums.size();
        reverseArray(nums,0 ,nums.size()-k-1); // first 
        reverseArray(nums, nums.size()-k, nums.size()-1); // second
        reverseArray(nums, 0,nums.size()-1);
        
    }
};

