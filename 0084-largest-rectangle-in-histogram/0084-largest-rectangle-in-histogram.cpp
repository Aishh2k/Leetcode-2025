class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left_smaller(n, -1);
        stack<int> st;
        //The stack stores indices of bars that are potential nearest smaller elements for future bars.

        for(int i = 0;i<n;i++){ // left smaller
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(!st.empty()){
                left_smaller[i] = st.top();
            }
            st.push(i);
        }

        while(!st.empty()){ // emptying stack
            st.pop();
        }

        vector<int> right_smaller(n, n);

        for(int i = n-1;i>=0;i--){ // right smaller
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(!st.empty()){
                right_smaller[i] = st.top();
            }

            st.push(i);
        }

        int ans = INT_MIN;
        for(int i = 0;i<n;i++){
            int area = heights[i] * (right_smaller[i] - left_smaller[i] - 1);
            ans = max(area, ans);
        }

        return ans; 
    }
};