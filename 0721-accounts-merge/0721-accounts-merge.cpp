class Solution {
public:
    int find(int node, vector<int>& root){
        if(root[node] != node){
            root[node] = find(root[node], root);
        }
        return root[node];
    }

    void unite(int a, int b, vector<int>& root){
        int ra = find(a, root);
        int rb = find(b, root);
        if(ra != rb){
            root[rb] = ra;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        vector<int> root(n);
        for(int i =0;i<n;i++){
            root[i] = i;
        }

        unordered_map<string, int> emToAcc;
        for(int i =0;i<n;i++){
            for(int j =1;j<accounts[i].size();j++){
                if(emToAcc.find(accounts[i][j]) == emToAcc.end()){
                    emToAcc[accounts[i][j]] = i;
                }else{
                    int prevAcc = emToAcc[accounts[i][j]];
                    unite(prevAcc, i, root);
                }
            }
        }
        unordered_map<int, vector<string>> accToEm;

        for(auto[email, acc]: emToAcc){
            accToEm[find(acc, root)].push_back(email);
        }

        vector<vector<string>> ans;

        for(auto[acc, emails]: accToEm){
            sort(emails.begin(), emails.end());
            vector<string> temp;
            temp.push_back(accounts[acc][0]);

            for(string em: emails){
                temp.push_back(em);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};