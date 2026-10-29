
class Solution {
    int LOG;
    vector<vector<int>> adj, up;
    vector<int> depth, tin, tout;
    vector<int> bit;
    int timer;

    void add(int idx, int val) {
        for (int i = idx; i < (int)bit.size(); i += i & -i)
            bit[i] ^= val;
    }

    int prefixXor(int idx) {
        int res = 0;
        for (int i = idx; i > 0; i -= i & -i)
            res ^= bit[i];
        return res;
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];

        for (int j = 0; j < LOG; j++) {
            if ((diff >> j) & 1)
                u = up[j][u];
        }

        if (u == v)
            return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[j][u] != up[j][v]) {
                u = up[j][u];
                v = up[j][v];
            }
        }

        return up[0][u];
    }

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        adj.assign(n, {});

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        LOG = 1;
        while ((1LL << LOG) <= n)
            LOG++;

        up.assign(LOG, vector<int>(n, 0));
        depth.assign(n, 0);
        tin.assign(n, 0);
        tout.assign(n, 0);

        timer = 0;
        vector<int> parent(n, -1);
        vector<int> order;
        order.reserve(n);

        stack<int> st;
        st.push(0);
        parent[0] = 0;

        while (!st.empty()) {
            int u = st.top();
            st.pop();

            tin[u] = ++timer;
            order.push_back(u);

            up[0][u] = parent[u];

            for (int j = 1; j < LOG; j++) {
                up[j][u] = up[j - 1][up[j - 1][u]];
            }

            for (int v : adj[u]) {
                if (v == parent[u])
                    continue;

                parent[v] = u;
                depth[v] = depth[u] + 1;
                st.push(v);
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            int u = order[i];
            tout[u] = tin[u];

            for (int v : adj[u]) {
                if (parent[v] == u)
                    tout[u] = max(tout[u], tout[v]);
            }
        }

        bit.assign(n + 2, 0);

        auto updateRange = [&](int l, int r, int val) {
            add(l, val);
            add(r + 1, val);
        };

        for (int u = 0; u < n; u++) {
            int mask = 1 << (s[u] - 'a');
            updateRange(tin[u], tout[u], mask);
        }

        vector<bool> ans;

        for (string& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;

            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;

                if (s[u] == c)
                    continue;

                int oldMask = 1 << (s[u] - 'a');
                int newMask = 1 << (c - 'a');

                int delta = oldMask ^ newMask;

                updateRange(tin[u], tout[u], delta);

                s[u] = c;
            }
            else {
                int u, v;
                ss >> u >> v;

                int w = lca(u, v);

                int mask = prefixXor(tin[u])
                         ^ prefixXor(tin[v])
                         ^ (1 << (s[w] - 'a'));

                bool valid = (mask & (mask - 1)) == 0;

                ans.push_back(valid);
            }
        }

        return ans;
    }
};
