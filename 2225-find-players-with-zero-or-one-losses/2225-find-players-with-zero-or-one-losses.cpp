class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> mp;
        unordered_set<int> winners;
        for(auto i: matches){
            if(winners.count(i[1])){
                winners.erase(i[1]);
            }
            mp[i[1]]++;
            if(mp.find(i[0]) == mp.end()){
                winners.insert(i[0]);
            }
        }
        vector<vector<int>> ans;
        vector<int> win(winners.begin(), winners.end());
        sort(win.begin(), win.end());
        ans.push_back(win);
        vector<int> loser;

        for(auto i: mp){
            if(i.second == 1){
                loser.push_back(i.first);
            }
        }
        sort(loser.begin(), loser.end());
        ans.push_back(loser);
        return ans;
        
    }
};