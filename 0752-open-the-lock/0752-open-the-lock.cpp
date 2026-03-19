class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> blocked (deadends.begin(), deadends.end());

        if(blocked.count("0000")){
            return -1;
        }

        queue<pair<string, int>>q;
        q.push({"0000", 0});

        unordered_set<string> visited;
        visited.insert("0000");

        while(!q.empty()){
            auto [state, val] = q.front();
            q.pop();
            if(state==target){
                return val;
            }

            int j;
            for(j =0;j<4;j++){
                if(state[j] != target[j]){
                    break;
                }
            }
            
            for(int i =j;i<state.size();i++){
                string up = state;
                string down = state;

                up[i] = (state[i] == '9')? '0': state[i]+1;
                down[i] = (state[i] == '0')? '9': state[i]-1;
                
                if(!visited.count(up) && !blocked.count(up)){
                    q.push({up,val+1});
                    visited.insert(up);
                }
                if(!visited.count(down) && !blocked.count(down)){
                    q.push({down,val+1});
                    visited.insert(down);
                }
            } 
        }

        return -1;
        
    }
};


