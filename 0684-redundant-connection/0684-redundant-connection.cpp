class Solution {
public:
    int find(int node, vector<int>&parent) {
        if (node != parent[node]) {
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
            if (find(u, parent) == find(v, parent)) {
                return edge;
            } else {
                parent[v] = u;
            }
        }

        return {-1, -1};
    }
};