// class Solution {
// public:
//     string simplifyPath(string path) {
//         stack<string> st;
//         string cur = "";

//         for (int i = 0; i <= path.size(); i++) {
//             if (i == path.size() || path[i] == '/') {
//                 if (cur.empty() || cur == ".") {
//                     cur = "";
//                     continue;
//                 } else if (cur == "..") {
//                     if (!st.empty()) {
//                         st.pop();
//                     }
//                 } else {
//                     st.push(cur);
//                 }
//                 cur = "";
//             }else{
//                 cur += path[i];
//             }
//         }
//         if(st.empty()){
//             return "/";
//         }
//         string ans = "";
//         while(!st.empty()){
//             cout<<ans<<endl;
//             ans = "/" + st.top()+ ans;
//             st.pop();
//         }
//         return ans;
//     }
// };

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string cur = "";

        for (int i = 0; i <= path.size(); i++) {
            if (i == path.size() || path[i] == '/') {
                if (cur.empty() || cur == ".") {
                    // ignore
                }
                else if (cur == "..") {
                    if (!st.empty()) {
                        st.pop_back();
                    }
                }
                else {
                    st.push_back(cur);
                }

                cur = "";
            }
            else {
                cur += path[i];
            }
        }

        string ans = "";

        for (string folder : st) {
            ans += "/";
            ans += folder;
        }

        if (ans == "") {
            return "/";
        }

        return ans;
    }
};