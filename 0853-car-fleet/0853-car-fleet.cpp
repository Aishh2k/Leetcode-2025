class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> pos_time;
        for(int i = 0;i<speed.size();i++){
            pos_time.push_back({position[i], ((double)target - position[i])/speed[i]});
        }
        
        sort(pos_time.begin(), pos_time.end());
        int count = 0;
        double cur_fleet = 0;
        for(int i = speed.size()-1;i>=0;i--){
            if(count == 0){
                cur_fleet = pos_time[i].second;
                count++;
            }else{
                if(pos_time[i].second > cur_fleet){
                    cur_fleet = pos_time[i].second;
                    count++;
                }
            }
        }

        return count;
        
    }
};