class Solution {
public:
    int find(int a, vector<int>&root){
        if(root[a] != a){
            root[a] = find(root[a], root);
        }
        return(root[a]);
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> root(n);
        for(int i =0;i<n;i++){
            root[i] = i;
        }

        unordered_map<string, int> emToAcc;
        for(int i = 0;i<accounts.size();i++){
            for(int j = 1;j<accounts[i].size();j++){
                if(emToAcc.find(accounts[i][j]) == emToAcc.end()){
                    emToAcc[accounts[i][j]] = i;
                }else{
                    int rb = find(i,root);
                    int ra = find(emToAcc[accounts[i][j]], root);
                    root[rb] = ra;
                }
            }
        }

        unordered_map<int, vector<string>> accToEm;

        for(auto[email, acc]: emToAcc){
            accToEm[find(acc,root)].push_back(email);
        }

        vector<vector<string>> ans;

        for(auto[acc,emails]: accToEm){
            vector<string> temp;
            temp.push_back(accounts[acc][0]);
            for(string em: emails){
                temp.push_back(em);
            }
            sort(temp.begin()+1, temp.end());
            ans.push_back(temp);
        }
        return ans;
    }
};