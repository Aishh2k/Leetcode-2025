class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for(char c : s){
            if(c != ']'){
                st.push(string{c});
            }else{
                string cur = "";
                while(!st.empty() && st.top()!= "["){
                    cur = st.top() + cur;
                    st.pop();
                }
                st.pop();
                string num = "";
                while(!st.empty() && isdigit(st.top()[0])){
                    num = st.top() + num;
                    st.pop();
                }
                string repeated = "";
                for(int i =0;i<stoi(num);i++){
                    repeated += cur;
                }
                st.push(repeated);
            }
        }  
        string ans = "";
        while(!st.empty()){
            ans  = st.top() + ans;
            st.pop();
        }     
        return ans; 
    }
};