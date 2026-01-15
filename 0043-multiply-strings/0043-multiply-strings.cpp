class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int m = num2.size();
        int n = num1.size();

        vector<int> ans(m+n, 0);

        for(int i = n-1;i>=0;i--){
            for(int j =m-1;j>=0;j--){
                int p1 = i+j+1;
                int p2 = i+j;

                int res = (num1[i] - '0') * (num2[j] - '0');
                int sum = res + ans[p1];
                ans[p1] = sum%10;
                ans[p2] += sum/10;
            }
        }

        string result = "";
        for(int i : ans){
            if(!(i==0  && result.empty())){
                result+= to_string(i);
            }
        }

        return result;
        
    }
};