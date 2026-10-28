
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // dp[j][x] = whether XOR x is reachable at column j
        vector<bitset<1024>> dp(n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bitset<1024> curr;
                int val = grid[i][j];

                if (i == 0 && j == 0) {
                    curr[val] = 1;
                } else {
                    bitset<1024> prev;

                    if (i > 0)
                        prev |= dp[j];

                    if (j > 0)
                        prev |= dp[j - 1];

                    for (int x = 0; x < 1024; x++) {
                        if (prev[x])
                            curr[x ^ val] = 1;
                    }
                }

                dp[j] = curr;
            }
        }

        for (int x = 0; x < 1024; x++) {
            if (dp[n - 1][x])
                return x;
        }

        return -1;
    }
};
