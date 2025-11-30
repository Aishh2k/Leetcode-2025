class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> pq(stones.begin(), stones.end());
        while(pq.size()>1){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();

            int diff = abs(x-y);
            if(diff!= 0){
                pq.push(diff);
            }
        }
        
        if(!pq.empty()){
            return(pq.top());   
        }else{
            return 0;
        }
    }
};
