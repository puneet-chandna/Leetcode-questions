class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        constexpr int MOD = 1'000'000'007;
        vector<int> dp(n, 0);  
        dp[0] = 1;
        long share = 0;
        for (int i = 1; i < n; ++i) {
            if (i - delay >= 0) share = (share + dp[i - delay]) % MOD;
            if (i - forget >= 0) share = (share - dp[i - forget] + MOD) % MOD;
            dp[i] = share;
        }
        long ans = 0;
        for (int i = n - forget; i < n; ++i)
            ans = (ans + dp[i]) % MOD;
        return (int)ans;
    }
};