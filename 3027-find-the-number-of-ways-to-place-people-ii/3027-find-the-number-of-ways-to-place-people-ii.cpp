class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();

        vector<long long> xs, ys;
        for (auto &p : points) {
            xs.push_back(p[0]);
            ys.push_back(p[1]);
        }
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());

        vector<pair<int,int>> comp(n);
        for (int i = 0; i < n; i++) {
            int cx = lower_bound(xs.begin(), xs.end(), points[i][0]) - xs.begin();
            int cy = lower_bound(ys.begin(), ys.end(), points[i][1]) - ys.begin();
            comp[i] = {cx, cy};
        }

        int X = xs.size(), Y = ys.size();
        vector<vector<int>> grid(X+1, vector<int>(Y+1, 0));

        for (auto [cx, cy] : comp) grid[cx+1][cy+1]++;

        
        for (int i = 1; i <= X; i++) {
            for (int j = 1; j <= Y; j++) {
                grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
            }
        }

        auto rectCount = [&](int x1, int y1, int x2, int y2) {
         
            return grid[x2+1][y2+1] - grid[x1][y2+1] - grid[x2+1][y1] + grid[x1][y1];
        };

        int ans = 0;
        for (int i = 0; i < n; i++) {
            auto [xi, yi] = comp[i];
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                auto [xj, yj] = comp[j];
                if (points[i][0] <= points[j][0] && points[i][1] >= points[j][1]) {
                    int cnt = rectCount(min(xi,xj), min(yi,yj), max(xi,xj), max(yi,yj));
                    if (cnt == 2) ans++;
                }
            }
        }

        return ans;
    }
};