class Solution {
public:
    int numberOfWays(int n, int x) {
        const int MOD = 1'000'000'007;
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int a = 1; ; ++a) {
            long long ax = 1;
            for (int i = 0; i < x; ++i) ax *= a;
            if (ax > n) break;
            int p = (int)ax;
            for (int i = n; i >= p; --i) {
                dp[i] = (dp[i] + dp[i - p]) % MOD;
            }
        }
        return dp[n];
    }
};