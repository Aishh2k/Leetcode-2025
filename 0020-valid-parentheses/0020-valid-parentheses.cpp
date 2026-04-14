class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char c : s){
            if(c == '(' || c == '{' || c == '['){
                st.push(c);
            }else{
                if(st.empty()){
                    return false;
                }
                char a = st.top();
                st.pop();

                if(c == ')'){
                    if(a != '('){
                        return false;
                    }
                }else if(c == ']'){
                    if(a != '['){
                        return false;
                    }
                }if(c == '}'){
                    if(a != '{'){
                        return false;
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