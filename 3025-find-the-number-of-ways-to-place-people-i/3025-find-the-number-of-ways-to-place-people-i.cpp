class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            int xi = points[i][0], yi = points[i][1];
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int xj = points[j][0], yj = points[j][1];
                if (xi <= xj && yi >= yj) {
                    int minx = min(xi, xj), maxx = max(xi, xj);
                    int miny = min(yi, yj), maxy = max(yi, yj);
                    bool ok = true;
                    for (int k = 0; k < n && ok; k++) {
                        if (k == i || k == j) continue;
                        int xk = points[k][0], yk = points[k][1];
                        if (xk >= minx && xk <= maxx && yk >= miny && yk <= maxy) ok = false;
                    }
                    if (ok) ans++;
                }
            }
        }
        return ans;
    }
};