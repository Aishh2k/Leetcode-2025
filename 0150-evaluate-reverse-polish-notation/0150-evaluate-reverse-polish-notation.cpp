class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(string s: tokens){
            if(s != "+" && s != "-" && s != "/" && s != "*"){
                st.push(stoi(s));
            }else{
                if(st.size() >= 2){
                    int b = st.top();
                    st.pop();
                    int a = st.top();
                    st.pop();

                    if(s == "+"){
                        st.push(a+b);
                    }else if(s == "-"){
                        st.push(a-b);
                    }if(s == "/"){
                        st.push(a/b);
                    }if(s == "*"){
                        st.push(a*b);
                    }
                }
            }
        }

        return st.top();
        
    }
};