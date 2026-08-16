class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;
        for(int num : st){
            if(!st.count(num -1)){
                int c = 1;
                while(st.count(num+c)){
                    c++;
                }
                ans = max(ans, c);
            }
        }
        return ans;
    }
};