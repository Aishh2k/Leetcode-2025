class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> ans(t.size(), 0);
        stack<int> st;
        int i = t.size()-1;
        
        while(i>=0){
            while(!st.empty() && t[st.top()] <= t[i]){
                st.pop();
            }

            if(!st.empty()){
                ans[i] = st.top() - i;
            }

            st.push(i);
            i--;
        }

        return ans;
        
    }
}; 