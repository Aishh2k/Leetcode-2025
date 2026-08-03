class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int ans = 1;
        int len = 1;

        for(int i = 1;i<arr.size();i++){
            bool alt = i>=2 && ((arr[i-2]>arr[i-1]  && arr[i-1] < arr[i])|| (arr[i-2] < arr[i-1] && arr[i-1] > arr[i]));

            if(alt){
                len++;
            }else if(arr[i-1] != arr[i]){
                len = 2;
            }else{
                len = 1;
            }

            ans = max(ans, len);
        }

        return ans;
        
    }
};