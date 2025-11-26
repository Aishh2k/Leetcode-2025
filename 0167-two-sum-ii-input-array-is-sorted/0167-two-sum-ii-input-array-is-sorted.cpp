class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;

        int l = 0;
        int r = numbers.size() - 1;
        int sum = 0;

        while (l < r) {
            sum = numbers[l] + numbers[r];
            if (sum == target) {
                res.push_back(l + 1);
                res.push_back(r + 1);
                return res;
            } else if (sum > target) {
                r--;
            } else {
                l++;
            }
        }

        return res;
    }
};
