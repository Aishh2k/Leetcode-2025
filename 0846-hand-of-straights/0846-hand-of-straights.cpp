class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0){
            return false;
        }
        unordered_map<int, int> mp;
        for(int i: hand){
            mp[i]++;
        }
        sort(hand.begin(), hand.end());

        for(int i =0;i<hand.size();i++){
            if(mp[hand[i]] <=0){
                continue;
            }

            int start = hand[i];
            for(int j =0;j<groupSize;j++){
                int t = start +j;
                if(mp[t] <= 0)
                    return false;
                
                mp[t]--;
            }
        }
        return true;
    }
};