class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int l = 0;
        unordered_set<int> window;

        for(int r=0;r<nums.size();r++){
            if(r-l>k){ //window too big
                window.erase(nums[l]);
                l++;
            }
            if(window.count(nums[r])){ // check in window
                return true;
            }else{
                window.insert(nums[r]); // insert into window
            }

        }

        return false;
        
    }
};