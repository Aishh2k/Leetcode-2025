class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size(), 1);
        vector<int> right(nums.size(),1);

        for(int i = 1;i<left.size();i++){
            left[i] = nums[i-1] * left[i-1];
        }

        for(int i = right.size()-2;i>=0;i--){
            right[i] = nums[i+1] * right[i+1];
        }

        vector<int> ans;

        for(int i = 0;i<left.size();i++){
            ans.push_back(left[i] * right[i]);
        }

        return ans;
        
    }
};

//[a,b,c,d]

//left
//1 a ab adc

// right
// bcd bc d 1