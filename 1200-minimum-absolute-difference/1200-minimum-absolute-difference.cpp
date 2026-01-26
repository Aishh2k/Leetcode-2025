class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        sort(arr.begin(), arr.end());
        int minVal = INT_MAX;

        for (int i = 1; i < arr.size(); i++) {
            minVal = min(minVal, arr[i] - arr[i - 1]);
        }

        for (int i = 1; i < arr.size(); i++) {
            int dif = arr[i] - arr[i - 1];
            if (dif == minVal) {
                res.push_back({arr[i - 1], arr[i]});
            }
        }

        return res;
    }
};