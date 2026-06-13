class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i = 0;i<asteroids.size();i++){
            if(asteroids[i]>0){
                st.push(asteroids[i]);
            }else{
                bool alive = true;
                while(!st.empty() && st.top()>0){
                    if(abs(asteroids[i]) == st.top()){
                        alive = false;
                        st.pop();
                        break;
                    }else if(abs(asteroids[i]) > st.top()){
                        st.pop();
                        alive = true;
                    }else{
                        alive = false;
                        break;
                    }    
                }
                if(alive){
                    st.push(asteroids[i]);
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