class Solution {
public:
    int find(int a, vector<int>&root){
        if(root[a] != a){
            root[a] = find(root[a], root);
        }
        return root[a];
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size()<n-1){
            return -1;
        }
        vector<int>root(n);
        for(int i =0;i<n;i++){
            root[i]=i;
        }

        int comp = n;
        for(auto edge: connections){
            int a = edge[0];
            int b = edge[1];

            int ra = find(a,root);
            int rb = find(b,root);

            if(ra!= rb){
                comp--;
                root[rb] = ra;
            }
        }

        return(comp-1);
        
    }
};