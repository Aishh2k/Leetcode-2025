class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> ct;

        for(int i =0;i<position.size();i++){
            ct.push_back(make_pair(position[i], ((double)target-position[i])/speed[i]));
        }
        sort(ct.rbegin(), ct.rend());

        int fleetCount = 0;
        double fleetTime = 0;

        for(auto p : ct){
            if(fleetCount == 0){
                fleetCount++;
                fleetTime = p.second;
            }else{
                if(p.second > fleetTime){
                    fleetCount++;
                    fleetTime = p.second;
                }
            }
        }

        return fleetCount;
        
    }
};