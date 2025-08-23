class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        int ans = m * n;

        for (int i = 0; i < m; ++i) {
            int top = area(grid, 0, i, 0, n - 1);
            if (top == 0) continue;
            for (int j = i + 1; j < m; ++j) {
                int mid = area(grid, i + 1, j, 0, n - 1);
                int bot = area(grid, j + 1, m - 1, 0, n - 1);
                if (mid == 0 || bot == 0) continue;
                ans = min(ans, top + mid + bot);
            }
        }

        for (int j = 0; j < n; ++j) {
            int left = area(grid, 0, m - 1, 0, j);
            if (left == 0) continue;
            for (int k = j + 1; k < n; ++k) {
                int mid = area(grid, 0, m - 1, j + 1, k);
                int right = area(grid, 0, m - 1, k + 1, n - 1);
                if (mid == 0 || right == 0) continue;
                ans = min(ans, left + mid + right);
            }
        }

        for (int i = 0; i < m - 1; ++i) {
            int top = area(grid, 0, i, 0, n - 1);
            if (top == 0) continue;
            for (int j = 0; j < n - 1; ++j) {
                int bl = area(grid, i + 1, m - 1, 0, j);
                int br = area(grid, i + 1, m - 1, j + 1, n - 1);
                if (bl == 0 || br == 0) continue;
                ans = min(ans, top + bl + br);
            }
        }

        for (int j = 0; j < n - 1; ++j) {
            int left = area(grid, 0, m - 1, 0, j);
            if (left == 0) continue;
            for (int i = 0; i < m - 1; ++i) {
                int tr = area(grid, 0, i, j + 1, n - 1);
                int br = area(grid, i + 1, m - 1, j + 1, n - 1);
                if (tr == 0 || br == 0) continue;
                ans = min(ans, left + tr + br);
            }
        }

        return ans;
    }


    int area(const vector<vector<int>>& g, int si, int ei, int sj, int ej) {
        int x1 = INT_MAX, y1 = INT_MAX, x2 = -1, y2 = -1;
        for (int x = si; x <= ei; ++x)
            for (int y = sj; y <= ej; ++y)
                if (g[x][y] == 1) {
                    x1 = min(x1, x);
                    y1 = min(y1, y);
                    x2 = max(x2, x);
                    y2 = max(y2, y);
                }
        return x2 == -1 ? 0 : (x2 - x1 + 1) * (y2 - y1 + 1);
    }
};