class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int rmax = INT_MIN;
        int lmax = INT_MIN;

        int r = height.size()-1;
        int l = 0;

        while(l<r){
            rmax = max(rmax, height[r]);
            lmax = max(lmax, height[l]);

            if(rmax < lmax){
                ans += rmax-height[r];
                r--;
            }else{
                ans += lmax-height[l];
                l++;
            }
        }

        return ans;
        
    }
};