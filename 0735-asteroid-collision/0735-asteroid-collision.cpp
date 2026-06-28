class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i : asteroids){
            if(i>0){
                st.push(i);
            }else{
                int alive = true;
                while(alive && !st.empty() && st.top() >0){
                    if(st.top() ==  abs(i)){
                        st.pop();
                        alive = false;
                    }else if(st.top()< abs(i)){
                        st.pop();
                    }else {
                        alive = false;
                    }
                }
                if(alive){
                    st.push(i);
                }
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};