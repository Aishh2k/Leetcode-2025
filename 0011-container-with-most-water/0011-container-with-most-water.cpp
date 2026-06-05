class Solution {
public:
    int maxArea(vector<int>& height) {
        int r = height.size() - 1;
        int l = 0;
        int maxArea = 0;
        int area = 0;

        while (l < r) {
            if (height[r] < height[l]) {
                area = height[r] * (r - l);
                r--;
            } else {
                area = height[l] * (r - l);
                l++;
            }

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};