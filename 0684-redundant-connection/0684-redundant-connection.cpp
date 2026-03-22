class Solution {
public:
    vector<int> root;
    int find(int a) {
        if (root[a] != a) {
            root[a] = find(root[a]);
        }
        return root[a];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for (int i = 0; i <= edges.size(); i++) {
            root.push_back(i);
        }

        for (auto i : edges) {
            int a = i[0];
            int b = i[1];

            int ra = find(a);
            int rb = find(b);

            if (ra == rb) {
                return i;
            } else {
                root[rb] = ra;
            }
        }
        return {-1,-1};
    }
};