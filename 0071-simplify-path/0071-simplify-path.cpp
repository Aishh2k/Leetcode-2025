class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string cur = "";

        for (int i = 0; i <= path.size(); i++) {
            if (i == path.size() || path[i] == '/') {
                if (cur.empty() || cur == ".") {
                    cur = "";
                    continue;
                } else if (cur == "..") {
                    if (!st.empty()) {
                        st.pop();
                    }
                } else {
                    st.push(cur);
                }
                cur = "";
            }else{
                cur += path[i];
            }
        }
        if(st.empty()){
            return "/";
        }
        string ans = "";
        while(!st.empty()){
            cout<<ans<<endl;
            ans = "/" + st.top()+ ans;
            st.pop();
        }
        return ans;
    }
};