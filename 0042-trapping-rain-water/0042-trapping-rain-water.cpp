class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        vector<int> right_max(height.size(), 0);
        vector<int> left_max(height.size(), 0)
;
        left_max[0] = height[0];
        for(int i = 1;i<height.size();i++){
            left_max[i] = max(height[i], left_max[i-1]);
        }

        right_max[height.size()-1] = height[height.size()-1];
        for(int i = height.size()-2;i>=0;i--){
            right_max[i] = max(height[i], right_max[i+1]);
        }

        for(int i = 0;i<height.size();i++){
            int water = min(left_max[i], right_max[i]) - height[i];

            if(water>0){
                ans += water;
            }
        }

        return ans;
        
    }
};