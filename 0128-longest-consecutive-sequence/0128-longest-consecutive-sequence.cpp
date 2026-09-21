class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len = 0;

        unordered_set<int> st(nums.begin(), nums.end());

        for(int i : st){
            if(!st.count(i-1)){
                int count = 1;
                while(st.count(i + count)){
                    count++;
                }
                len = max(len, count);
            }
        }

        return len;
        
    }
};