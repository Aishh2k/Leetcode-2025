class Solution {
public:
    int find(int a, vector<int>&root){
        if(a != root[a]){
            root[a] = find(root[a], root);
        }

        return root[a];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> root(edges.size()+1, 0);
        for(int i = 0;i<=edges.size();i++){
            root[i] = i;
        }

        for(auto edge: edges){
            int a = edge[0];
            int b = edge[1];

            int ra = find(a, root);
            int rb = find(b, root);
            if(ra == rb){
                return edge;
            }

            root[rb] = ra;
        }

        return {-1,-1};
    }
};