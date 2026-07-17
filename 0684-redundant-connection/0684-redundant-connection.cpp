class Solution {
public:
    int find(int a, vector<int>& root) {
        if (root[a] != a) {
            root[a] = find(root[a], root);
        }
        return root[a];
    }
    bool unite(int a, int b, vector<int>& root) {
        int ra = find(a, root);
        int rb = find(b, root);

        if (ra == rb) {
            return false;
        } else {
            root[rb] = ra;
            return true;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // union find algorithm
        vector<int> root(edges.size() + 1);
        vector<int> ans;
        for (int i = 0; i < edges.size(); i++) {
            root[i] = i;
        }

        for (auto edge : edges) {
            if (!unite(edge[0], edge[1], root)) {
                ans.push_back(edge[0]);
                ans.push_back(edge[1]);
            }
        }

        return ans;
    }
};