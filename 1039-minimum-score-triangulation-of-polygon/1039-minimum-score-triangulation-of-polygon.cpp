class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
     
        vector<vector<int>> dp(n, vector<int>(n, 0));

      
        for (int length = 3; length <= n; ++length) {
            for (int i = 0; i + length - 1 < n; ++i) {
                int j = i + length - 1;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; ++k) {
                    long cost = (long)values[i] * values[k] * values[j];
                    cost += dp[i][k] + dp[k][j];
                    dp[i][j] = min(dp[i][j], (int)cost);
                }
            }
        }

        return dp[0][n - 1];
    }
};