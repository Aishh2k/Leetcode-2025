class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c: s){
            if(c == '(' || c == '[' || c == '{'){
                st.push(c);
            }else{
                if(st.empty()){
                    return false;
                }else{
                    char t = st.top();
                    st.pop();

                    if(c == '}'){
                        if(t != '{'){
                            return false;
                        }
                    }else if(c == ']'){
                        if(t != '['){
                            return false;
                        }
                    }else if(c == ')'){
                        if(t != '('){
                            return false;
                        }
                    }
                }
            }
        }

        if(!st.empty()){
            return false;
        }else{
            return true;
        }
        
    }
};