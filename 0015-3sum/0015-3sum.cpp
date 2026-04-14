class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i =0;i<nums.size();i++){
            while(i>0 && i<nums.size() && nums[i] == nums[i-1]){
                i++;
            }
            int r = nums.size()-1;
            int l = i+1;

            while(l<r){
                int sum = nums[r] + nums[l] + nums[i];
                if(sum == 0){
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;

                    while(l>0 && l<r && nums[l] == nums[l-1]){
                        l++;
                    }

                    while(r<nums.size()-1 && l<r && nums[r] == nums[r+1]){
                        r--;
                    }
                }else if(sum>0){
                    r--;
                }else{
                    l++;
                }
            }
        }

        return ans;
        
    }
};