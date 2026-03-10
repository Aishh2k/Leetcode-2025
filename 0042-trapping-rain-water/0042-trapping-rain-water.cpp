class Solution {
public:
    int trap(vector<int>& height) {

        int l =0;
        int r = height.size()-1;
        int lmax = 0;
        int rmax = 0;
        int res = 0;
        int val;

        while(l<=r){
            lmax = max(height[l], lmax);
            rmax = max(height[r], rmax);

            if(lmax<rmax){
                val = lmax - height[l];
                l++;
            }else{
                val = rmax - height[r];
                r--;
            }

            if(val>0){
                res += val;
            }
        }
        return res;   
    }
};