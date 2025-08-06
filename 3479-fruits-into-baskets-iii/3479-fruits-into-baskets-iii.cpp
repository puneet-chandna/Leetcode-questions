struct SegmentTree {
    int n;
    vector<int> st;
    SegmentTree(const vector<int>& A) {
        n = A.size();
        st.assign(4*n, 0);
        build(A, 1, 0, n-1);
    }

    void build(const vector<int>& A, int p, int l, int r) {
        if (l == r) {
            st[p] = A[l];
            return;
        }
        int m = (l + r) / 2;
        build(A, p*2, l, m);
        build(A, p*2+1, m+1, r);
        st[p] = max(st[p*2], st[p*2+1]);
    }

    // Find leftmost index ≥ current i within [ql..qr] where st value ≥ x.
    int queryFirst(int x, int p, int l, int r) {
        if (st[p] < x) return -1;
        if (l == r) return l;
        int m = (l + r) / 2;
        if (st[p*2] >= x) return queryFirst(x, p*2, l, m);
        return queryFirst(x, p*2+1, m+1, r);
    }

    int findAndUse(int x) {
        int idx = queryFirst(x, 1, 0, n-1);
        if (idx != -1) {
            update(idx, 0, 1, 0, n-1);
        }
        return idx;
    }

    void update(int q, int val, int p, int l, int r) {
        if (l == r) {
            st[p] = val;
            return;
        }
        int m = (l + r) / 2;
        if (q <= m) update(q, val, p*2, l, m);
        else update(q, val, p*2+1, m+1, r);
        st[p] = max(st[p*2], st[p*2+1]);
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size(), unplaced = 0;
        SegmentTree tree(baskets);
        for (int f : fruits) {
            if (tree.findAndUse(f) == -1) ++unplaced;
        }
        return unplaced;
    }
};