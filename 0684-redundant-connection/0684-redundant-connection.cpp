class Solution {
public:
    int find(int node, vector<int>&parent) {
        while(node != parent[node]) {
            parent[node] = parent[parent[node]];
            node = parent[node];
        }
        return node;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(edges.size() + 1);
        for (int i = 1; i <= edges.size(); i++) {
            parent[i] = i;
        }

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            int root1 = find(u, parent);
            int root2 = find(v, parent);
            if ( root1 == root2) {
                return edge;
            }
            parent[root2] = root1;
        }

        return {-1, -1};
    }
};