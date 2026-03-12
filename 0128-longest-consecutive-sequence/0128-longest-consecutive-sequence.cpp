class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int res = 0;

        for(int i : st){
            if(!st.count(i-1)){
                int a = 1;
                while(st.count(i+a)){
                    a++;
                }

                res = max(res,a);
            }
        }

        return res;
        
    }
};