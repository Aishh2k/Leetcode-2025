class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if (n % groupSize != 0) {
            return false;
        }

        unordered_map<int, int> mp;
        sort(hand.begin(), hand.end());

        for (int i = 0; i < n; i++) {
            mp[hand[i]]++;
        }

        for (int j = 0; j < n; j++) {
            int cur = hand[j];
            if (mp[cur]!= 0) {
                for (int i = 0; i < groupSize; i++) {
                    int target = cur + i;

                    if(mp[target]==0){
                        return false;
                    }else{
                        mp[target]--;
                    }
                }
            }
        }

        return true;
    }
};