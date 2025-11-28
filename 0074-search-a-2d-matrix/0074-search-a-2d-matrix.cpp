class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0;
        int right = m * n - 1;
        int row;
        int col;
        int mid;

        while (left <= right) {
            mid = left + (right - left) / 2;
            row = mid / n; // no of col
            col = mid % n;

            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] < target) {
                left = mid +1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    }
};