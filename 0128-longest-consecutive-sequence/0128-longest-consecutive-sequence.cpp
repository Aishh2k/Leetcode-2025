class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size()<=1){
            return nums.size();
        }
        int ans = INT_MIN;
        unordered_set<int> st(nums.begin(), nums.end());

        for(int i : st){
            if(!st.count(i-1)){
                int c = 1;
                while(st.count(i+c)){
                    c++;
                }

                ans = max(ans, c);
            }
        }

        return ans;
        
    }
};