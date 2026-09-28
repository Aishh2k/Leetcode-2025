class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> st;

        for(int i = 0;i<position.size();i++){
            int a = position[i];
            double b = (double)(target-a)/ speed[i];
            st.push_back(make_pair(a,b));
        }

        sort(st.rbegin(), st.rend());
        int fleetcount = 0;
        double fleettime = 0;

        for(int i = 0;i<st.size();i++){
            if(fleetcount == 0){
                fleetcount++;
                fleettime = st[i].second;
            }else{
                if(st[i].second > fleettime){
                    fleetcount++;
                    fleettime = st[i].second;
                }
            }
        }

        return fleetcount;
        
    }
};