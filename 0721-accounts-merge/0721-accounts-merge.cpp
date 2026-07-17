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
                string email = accounts[i][j];
                if(emToAcc.find(email) == emToAcc.end()){
                    emToAcc[email] = i;
                }else{
                    int prevAccount = emToAcc[email];
                    unite(i, prevAccount, root);
                }
            }
        }

        unordered_map<int, vector<string>> mp;
        for(auto a: emToAcc){
            int rootAccount = find(a.second, root);
            mp[rootAccount].push_back(a.first);
        }
        vector<vector<string>> ans;

        for(auto[rootAcc, emails]: mp){
            sort(emails.begin(), emails.end());
            string name = accounts[rootAcc][0];
            vector<string> temp;
            temp.push_back(name);
            for(string em: emails){
                temp.push_back(em);
            }
            ans.push_back(temp);
        }

        return ans;

    }
};