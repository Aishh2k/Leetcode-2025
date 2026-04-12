class Solution {
public:
    int maxArea(vector<int>& height) {
        int l =0;
        int r = height.size()-1;
        int ans = 0;

        while(l<r){
            int minHeight = min(height[l], height[r]);
            ans = max(ans, minHeight * (r-l));

            if(height[l]>height[r]){
                r--;
            }else{
                l++;
            }
        }

        return ans;
        
    }
};