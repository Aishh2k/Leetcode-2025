class Solution {
public:
    int calPoints(vector<string>& operations) {
        int sum = 0;
        stack<int> res;

        for(int i =0;i<operations.size();i++){
            if(operations[i] == "C"){
                res.pop();
            }else if(operations[i] == "D"){
                res.push(res.top()*2);
            }else if(operations[i] == "+"){
                int a = res.top();
                res.pop();
                int b = res.top();
                res.push(a);
                res.push(a+b);
            }else{
                res.push(stoi(operations[i]));
            }
        }
        while(!res.empty()){
            sum+= res.top();
            res.pop();
        }

        return sum;
        
    }
};