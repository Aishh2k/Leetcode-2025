class Solution {
public:
    bool isPossible(int k, int h, vector<int> piles) {
        int count = 0;

        for (int i : piles) {
            count += ceil((double)i / k);

            if (count > h) {
                return false;
            }
        }

        if (count > h) {
            return false;
        }else{
            return true;
        }
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int res = 1;
        int high = *max_element(piles.begin(), piles.end());
        int mid = 0;

        while (low <= high) {
            mid = low + (high - low) / 2;
            if (isPossible(mid, h, piles)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return res;
    }
};