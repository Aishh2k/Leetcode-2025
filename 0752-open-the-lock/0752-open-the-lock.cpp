class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        queue<pair<string, int>> q;

        if(dead.count("0000")){
            return -1;
        }

        q.push({"0000",0});
        visited.insert("0000");

        while(!q.empty()){
            auto [state, step] = q.front();
            q.pop();

            if(state == target){
                return step;
            }

            for(int i =0;i<4;i++){
                string up = state;
                string down = state;

                up[i] = state[i]== '0' ? '9' :state[i]-1;
                down[i] = state[i]=='9'? '0': state[i]+1;

                if(!dead.count(up) && !visited.count(up)){
                    visited.insert(up);
                    q.push({up,step+1});
                }
                if(!dead.count(down) && !visited.count(down)){
                    visited.insert(down);
                    q.push({down,step+1});
                }
            }
        }

        return -1;
        
    }
};