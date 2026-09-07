class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> lossFreq;
        for (auto i : matches) {
            int win = i[0];
            int loss = i[1];

            lossFreq[loss]++;
            if (lossFreq.find(win) == lossFreq.end()) {
                lossFreq[win] = 0;
            }
        }
        vector<vector<int>> ans;
        vector<int> temp1;
        vector<int> temp2;
        for (auto p : lossFreq) {
            if (p.second == 0) {
                temp1.push_back(p.first);
            }else if(p.second == 1){
                temp2.push_back(p.first);
            }
        }

        sort(temp1.begin(), temp1.end());
        sort(temp2.begin(), temp2.end());
        ans.push_back(temp1);
        ans.push_back(temp2);
        return ans;


    }
};