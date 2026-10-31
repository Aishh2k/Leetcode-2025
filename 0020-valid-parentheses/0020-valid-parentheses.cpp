class Solution {
public:
    bool isValid(string st) {
        stack<char> s;
        for(int i = 0;i<st.size();i++){
            if(st[i] == '(' || st[i] == '[' || st[i] == '{'){
                s.push(st[i]);
            }else{
                if(s.empty()){
                    return false;
                }
                char a = s.top();
                s.pop();
                if(st[i] == ']'){
                    if (a != '['){
                        return false;
                    }
                } else if(st[i] == '}'){
                    if (a != '{'){
                        return false;
                    }
                }else if(st[i] == ')'){
                    if (a != '('){
                        return false;
                    }
                }
            }
        }

        if(s.empty()){
            return true;
        }else{
            return false;
        }
        
    }
};