class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int ans = INT_MIN;
        int water;

        while(l<r){
            if(height[l] < height[r]){
                water = (r-l) * height[l];
                l++;
            }else{
                water = (r-l) * height[r];
                r--;
            }
            ans = max(ans, water);
        }

        return ans;
        
    }
};