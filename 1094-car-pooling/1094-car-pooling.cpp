class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int cur_cap = 0;
        vector<pair<int, int>> events;

        for(int i = 0;i< trips.size();i++){
            events.push_back({trips[i][1], trips[i][0]});
            events.push_back({trips[i][2], -trips[i][0]});
        }

        sort(events.begin(), events.end());

        for(auto i: events){
            cur_cap += i.second;
            if(cur_cap > capacity){
                return false;
            }
        }

        return true;
        
    }
};

// (1,2) (3, 3) (5, -1)  (7, -3)