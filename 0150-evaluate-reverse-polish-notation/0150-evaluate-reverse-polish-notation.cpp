class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string c: tokens){
            if(c != "*" && c != "+" && c!= "-" && c != "/"){
                st.push(stoi(c));
            }else{
                if(st.size() <2){
                    return -1;
                }

                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();

                if(c == "*"){
                    st.push(a*b);
                }else if(c == "+"){
                    st.push(a+b);
                }else if(c == "/"){
                    st.push(a/b);
                }else if(c == "-"){
                    st.push(a-b);
                }
            }
        }

        return st.top();
        
        
    }
};