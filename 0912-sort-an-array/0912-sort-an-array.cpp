class Solution {
public:
    void merge(vector<int>& nums, int l, int m, int r){
        int i = l;
        int j = m+1;
        vector<int> temp;

        while(i<=m && j<=r){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i]);
                i++;
            }else{
                temp.push_back(nums[j]);
                j++;
            }
        }

        while(i<=m){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=r){
            temp.push_back(nums[j]);
            j++;
        }

        for(int k =0;k<temp.size();k++){
            nums[l+k] = temp[k];
        }
    }
    void mergeSort(vector<int>& nums, int l , int r){
        if(l == r){
            return;
        }
        int m = (l+r)/2;

        mergeSort(nums, l,m);
        mergeSort(nums,m+1, r);
        merge(nums, l, m, r);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};