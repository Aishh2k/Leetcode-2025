class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int res = 0;

        // next smaller to right

        stack<int> st;
        vector<int> right_index(n,-1);

        for(int i = 0;i<n;i++){
            while(!st.empty() && heights[i]< heights[st.top()]){
                right_index[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        // next smaller to left
        stack<int> left;
        vector<int> left_index(n,-1);

        for(int i = n-1;i>=0;i--){
            while(!left.empty() && heights[i]< heights[left.top()]){
                left_index[left.top()] = i;
                left.pop();
            }
            left.push(i);
        }

        // right index -1 cases
        for(int i =0;i<n;i++){
            if(right_index[i] == -1){
                right_index[i] = n;
            }
        }

        for(int i =0;i<n;i++){
            int width = right_index[i]-left_index[i]-1;
            int ans = heights[i] * width;
            res = max(res,ans);
        }

        return res;
        
    }
};