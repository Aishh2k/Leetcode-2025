class Solution {
public:
    int op(string val, int a, int b){
        if(val == "+"){
            return a+b;
        }else if (val == "*"){
            return a*b;
        }else if(val == "/"){
            return a/b;
        }else{
            return(a-b);
        }
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int b;
        int a;
        for(int i =0;i<tokens.size();i++){
            if(tokens[i] == "+" || tokens[i]=="-" || tokens[i] == "*" || tokens[i] == "/"){
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();
                st.push(op(tokens[i], a, b));
            }else{
                st.push(stoi(tokens[i]));
            }
        }

        return(st.top());
        
    }
};