class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
    auto area = [&](int r1, int r2, int c1, int c2)->int {
      if (r1 > r2 || c1 > c2) return 0;
      int rmin = INT_MAX, cmin = INT_MAX, rmax = -1, cmax = -1;
      for (int i = r1; i <= r2; ++i)
        for (int j = c1; j <= c2; ++j)
          if (grid[i][j]) {
            rmin = min(rmin, i); cmin = min(cmin, j);
            rmax = max(rmax, i); cmax = max(cmax, j);
          }
      return (rmax == -1) ? 0 : (rmax - rmin + 1) * (cmax - cmin + 1);
    };

    int ans = INT_MAX;

    // top + (bottom split L/R)
    for (int i = 0; i < m; ++i) {
      int top = area(0, i, 0, n - 1);
      for (int j = 0; j < n; ++j)
        ans = min(ans, top + area(i + 1, m - 1, 0, j) + area(i + 1, m - 1, j + 1, n - 1));
    }
    // bottom + (top split L/R)
    for (int i = 0; i < m; ++i) {
      int bottom = area(i, m - 1, 0, n - 1);
      for (int j = 0; j < n; ++j)
        ans = min(ans, bottom + area(0, i - 1, 0, j) + area(0, i - 1, j + 1, n - 1));
    }
    // left + (right split T/B)
    for (int j = 0; j < n; ++j) {
      int left = area(0, m - 1, 0, j);
      for (int i = 0; i < m; ++i)
        ans = min(ans, left + area(0, i, j + 1, n - 1) + area(i + 1, m - 1, j + 1, n - 1));
    }
    // right + (left split T/B)
    for (int j = 0; j < n; ++j) {
      int right = area(0, m - 1, j, n - 1);
      for (int i = 0; i < m; ++i)
        ans = min(ans, right + area(0, i, 0, j - 1) + area(i + 1, m - 1, 0, j - 1));
    }
   
    for (int r1 = 0; r1 < m; ++r1)
      for (int r2 = r1 + 1; r2 < m; ++r2)
        ans = min(ans, area(0, r1, 0, n - 1) +
                         area(r1 + 1, r2, 0, n - 1) +
                         area(r2 + 1, m - 1, 0, n - 1));
    // three vertical stripes
    for (int c1 = 0; c1 < n; ++c1)
      for (int c2 = c1 + 1; c2 < n; ++c2)
        ans = min(ans, area(0, m - 1, 0, c1) +
                         area(0, m - 1, c1 + 1, c2) +
                         area(0, m - 1, c2 + 1, n - 1));

    return ans;
    }
};