class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> tin(n), tout(n), depth(n);
        vector<int> parent(n);
        int timer = 0;

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n));

        function<void(int, int)> dfs = [&](int u, int p) {
            tin[u] = timer++;
            parent[u] = p;
            up[0][u] = p;

            for (int j = 1; j < LOG; j++)
                up[j][u] = up[j - 1][up[j - 1][u]];

            for (int v : adj[u]) {
                if (v == p) continue;
                depth[v] = depth[u] + 1;
                dfs(v, u);
            }

            tout[u] = timer;
        };

        dfs(0, 0);

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);

            int diff = depth[u] - depth[v];

            for (int j = 0; j < LOG; j++)
                if (diff & (1 << j))
                    u = up[j][u];

            if (u == v) return u;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][u] != up[j][v]) {
                    u = up[j][u];
                    v = up[j][v];
                }
            }

            return up[0][u];
        };

        vector<int> bit(n + 2, 0);

        auto update = [&](int i, int val) {
            for (; i <= n + 1; i += i & -i)
                bit[i] ^= val;
        };

        auto get = [&](int i) {
            int val = 0;
            for (; i > 0; i -= i & -i)
                val ^= bit[i];
            return val;
        };

        vector<int> mask(n);

        for (int i = 0; i < n; i++) {
            mask[i] = 1 << (s[i] - 'a');
            update(tin[i] + 1, mask[i]);
            update(tout[i] + 1, mask[i]);
        }

        vector<bool> ans;

        for (string q : queries) {
            stringstream ss(q);
            string op;
            int u, v;
            ss >> op >> u;

            if (op == "update") {
                char c;
                ss >> c;

                int newMask = 1 << (c - 'a');
                int diff = mask[u] ^ newMask;

                update(tin[u] + 1, diff);
                update(tout[u] + 1, diff);

                mask[u] = newMask;
                s[u] = c;
            } else {
                ss >> v;

                int w = lca(u, v);
                int pathMask = get(tin[u] + 1) ^
                               get(tin[v] + 1) ^
                               mask[w];

                ans.push_back((pathMask & (pathMask - 1)) == 0);
            }
        }

        return ans;
    }
};