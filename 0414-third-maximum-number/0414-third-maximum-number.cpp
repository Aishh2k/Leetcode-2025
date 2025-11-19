class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_set<int> s;
        for(int i: nums){
            s.insert(i);
        }
        priority_queue<int, vector<int>, greater<int>> q;

        for( int i : s){
            q.push(i);
            if(q.size()>3){
                q.pop();
            }
        }

        if(q.size()<3){
            while(!q.empty()){
                q.pop();
            }
        }
        return(q.top());

        
    }
};