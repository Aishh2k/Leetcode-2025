class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> R, D;
        int n = senate.size();

        for(int i =0;i<n;i++){ // store R and D indices
            if(senate[i] == 'R'){
                R.push(i);
            }else{
                D.push(i);
            }
        }

        while(!R.empty() && !D.empty()){
            int r = R.front();
            R.pop();
            int d = D.front();
            D.pop();

            if(r<d){
                R.push(r+n);
            }else{
                D.push(d+n);
            }
        }

        return R.empty()? "Dire": "Radiant";
        
    }
};