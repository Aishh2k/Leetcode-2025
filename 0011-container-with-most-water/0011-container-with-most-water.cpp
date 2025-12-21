class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA = 0;
        int l = 0;
        int r = height.size()-1;

        int area = 0;

        while(l<r){
            area = (r-l) * min(height[r], height[l]);
            maxA = max(maxA, area);
            if(height[r]>height[l]){
                l++;
            }else{
                r--;
            }
        }

        return maxA;
        
    }
};