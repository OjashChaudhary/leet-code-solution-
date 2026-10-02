class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        parent.resize(n + 1);

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        for (auto edge : edges) {
            int x = find(edge[0]);
            int y = find(edge[1]);

            if (x == y) {
                return edge;
            }

            parent[x] = y;
        }

        return {};
    }
};