
class Solution {
    static const int MOD = 1e9 + 7;

    struct Node {
        long long sum = 0;
        long long sumSq = 0;
        long long lazy = 0;
    };

    vector<Node> tree;
    int n;

    void apply(int node, int l, int r, long long val) {
        long long len = r - l + 1;

        tree[node].sumSq = (
            tree[node].sumSq
            + 2LL * val % MOD * tree[node].sum % MOD
            + len % MOD * val % MOD * val % MOD
        ) % MOD;

        tree[node].sum = (
            tree[node].sum + len % MOD * val % MOD
        ) % MOD;

        tree[node].lazy = (tree[node].lazy + val) % MOD;
    }

    void push(int node, int l, int r) {
        if (tree[node].lazy == 0 || l == r) return;

        int mid = l + (r - l) / 2;
        long long val = tree[node].lazy;
        apply(node * 2, l, mid, val);
        apply(node * 2 + 1, mid + 1, r, val);

        tree[node].lazy = 0;
    }

    void pull(int node) {
        tree[node].sum = (
            tree[node * 2].sum + tree[node * 2 + 1].sum
        ) % MOD;
        tree[node].sumSq = (
            tree[node * 2].sumSq + tree[node * 2 + 1].sumSq
        ) % MOD;
    }

    void update(int node, int l, int r,
                int ql, int qr, long long val) {
        if (ql > r || qr < l) return;

        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }

        push(node, l, r);

        int mid = l + (r - l) / 2;
        update(node * 2, l, mid, ql, qr, val);
        update(node * 2 + 1, mid + 1, r, ql, qr, val);

        pull(node);
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        tree.assign(4 * n, Node());

        vector<int> last(100001, -1);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int prev = last[nums[i]];
            update(1, 0, n - 1, prev + 1, i, 1);
            ans = (ans + tree[1].sumSq) % MOD;

            last[nums[i]] = i;
        }

        return ans;
    }
};
