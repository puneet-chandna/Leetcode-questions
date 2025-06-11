class Solution {
public:
    struct SegmentTree {
        vector<int> tree;
        int size;
        const int INF = 1e9;

        void build(int n) {
            size = 1;
            while (size < n) {
                size *= 2;
            }
            tree.assign(2 * size, INF);
        }

        void update(int i, int v, int x, int lx, int rx) {
            if (rx - lx == 1) {
                tree[x] = min(tree[x], v);
                return;
            }
            int m = lx + (rx - lx) / 2;
            if (i < m) {
                update(i, v, 2 * x + 1, lx, m);
            } else {
                update(i, v, 2 * x + 2, m, rx);
            }
            tree[x] = min(tree[2 * x + 1], tree[2 * x + 2]);
        }

        void update(int i, int v) {
            update(i, v, 0, 0, size);
        }

        int query(int l, int r, int x, int lx, int rx) {
            if (lx >= r || l >= rx) {
                return INF;
            }
            if (lx >= l && rx <= r) {
                return tree[x];
            }
            int m = lx + (rx - lx) / 2;
            int left = query(l, r, 2 * x + 1, lx, m);
            int right = query(l, r, 2 * x + 2, m, rx);
            return min(left, right);
        }

        int query(int l, int r) {
            return query(l, r, 0, 0, size);
        }
    };

    int maxDifference(string s, int k) {
        int n = s.length();
        vector<vector<int>> pref(5, vector<int>(n + 1, 0));
        for (int i = 0; i < n; ++i) {
            for (int c = 0; c < 5; ++c) {
                pref[c][i + 1] = pref[c][i];
            }
            pref[s[i] - '0'][i + 1]++;
        }

        int max_diff = -1e9; 
        bool found = false;

        for (int a_char = 0; a_char < 5; ++a_char) {
            for (int b_char = 0; b_char < 5; ++b_char) {
                if (a_char == b_char) continue;

                array<array<SegmentTree, 2>, 2> sts;
                for (int i = 0; i < 2; ++i) {
                    for (int j = 0; j < 2; ++j) {
                        sts[i][j].build(n + 1);
                    }
                }

                for (int j = k; j <= n; ++j) {
                    int i = j - k;
                    int pa_i = pref[a_char][i] % 2;
                    int pb_par_i = pref[b_char][i] % 2;
                    int pb_val_i = pref[b_char][i];
                    int v_i = pref[a_char][i] - pref[b_char][i];
                    sts[pa_i][pb_par_i].update(pb_val_i, v_i);
                    
                    int pa_j = pref[a_char][j] % 2;
                    int pb_par_j = pref[b_char][j] % 2;
                    int pb_val_j = pref[b_char][j];
                    int v_j = pref[a_char][j] - pref[b_char][j];

                    int pa_target = 1 - pa_j;
                    int pb_par_target = pb_par_j;
                    
                    int min_v_i = sts[pa_target][pb_par_target].query(0, pb_val_j);

                    if (min_v_i != sts[0][0].INF) {
                        max_diff = max(max_diff, v_j - min_v_i);
                        found = true;
                    }
                }
            }
        }
        
        return found ? max_diff : -1;
        
    }
};