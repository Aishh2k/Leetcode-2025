class Solution {
public:
    int result = INT_MAX;
    int findMax(vector<int>&sum){
        int ans = INT_MIN;

        for(int i : sum){
            if(i>ans){
                ans = i;
            }
        }

        return ans;
    }
    void dfs(int idx, vector<int>&cookies, vector<int>&sum, int k){
        if(idx>=cookies.size()){
            int a = findMax(sum);
            result = min(a, result);
            return;
        }

        int cookie = cookies[idx];
        for(int i =0;i<k;i++){
            sum[i] += cookie;
            dfs(idx+1, cookies, sum, k);
            sum[i] -= cookie;
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> sum(k, 0);
        dfs(0, cookies, sum, k);
        return result;
    }
};