class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char i : s){
            if(i=='(' || i =='['|| i== '{' ){
                st.push(i);
            }else{
                if(st.empty()){
                    return false;
                }else{
                    char t = st.top();
                    st.pop();
                    if(i == ')'){
                        if(t != '('){
                            return false;
                        }
                    }else if (i == '}'){
                        if(t != '{'){
                            return false;
                        }
                    }else{
                        if(t != '['){
                            return false;
                        }

                    }
                }
            }
        }

        if(!st.empty()){
            return (false);
        }

        return true;
        
    }
};