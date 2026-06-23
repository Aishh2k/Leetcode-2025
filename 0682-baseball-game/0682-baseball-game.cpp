class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;

        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "+") {
                int a = st.top(); //10
                st.pop();
                int b = st.top(); //5
                st.pop();

                st.push(b);
                st.push(a);
                st.push(a + b);
            } else if (operations[i] == "D") {
                st.push(st.top()*2);
            } else if (operations[i] == "C") {
                st.pop();
            }else{
                st.push(stoi(operations[i]));
            }
        }
        int ans = 0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};