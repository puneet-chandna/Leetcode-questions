class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        return collectMainDiagonal(fruits)
             + collectFromTopRight(fruits)
             + collectFromBottomLeft(fruits)
             - 2 * fruits.back().back();
    }
    private:
    int collectMainDiagonal(const vector<vector<int>>& fruits) {
        int n = fruits.size(), sum = 0;
        for (int i = 0; i < n; ++i)
            sum += fruits[i][i];
        return sum;
    }

    int collectFromTopRight(const vector<vector<int>>& fruits) {
        int n = fruits.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[0][n - 1] = fruits[0][n - 1];
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < n; ++y) {
                if (x >= y && !(x == n - 1 && y == n - 1)) continue;
                for (auto [dx, dy] : vector<pair<int,int>>{{1,-1},{1,0},{1,1}}) {
                    int i = x - dx, j = y - dy;
                    if (i < 0 || j < 0 || i >= n || j >= n) continue;
                    if (i < j && j < n - 1 - i) continue;
                    dp[x][y] = max(dp[x][y], dp[i][j] + fruits[x][y]);
                }
            }
        }
        return dp[n - 1][n - 1];
    }

    int collectFromBottomLeft(const vector<vector<int>>& fruits) {
        int n = fruits.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[n - 1][0] = fruits[n - 1][0];
        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < n; ++x) {
                if (x <= y && !(x == n - 1 && y == n - 1)) continue;
                for (auto [dx, dy] : vector<pair<int,int>>{{-1,1},{0,1},{1,1}}) {
                    int i = x - dx, j = y - dy;
                    if (i < 0 || j < 0 || i >= n || j >= n) continue;
                    if (j < i && i < n - 1 - j) continue;
                    dp[x][y] = max(dp[x][y], dp[i][j] + fruits[x][y]);
                }
            }
        }
        return dp[n - 1][n - 1];
    }
};