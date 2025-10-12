class Solution {
public:
    int magicalSum(int m, int k, vector<int>& nums) {
        const long long MOD = 1000000007LL;
        int n = (int)nums.size();
        vector<vector<long long>> comb(m+1, vector<long long>(m+1, 0));
        for (int i = 0; i <= m; ++i) {
            comb[i][0] = comb[i][i] = 1;
            for (int j = 1; j < i; ++j) comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % MOD;
        }
        vector<vector<long long>> poww(n, vector<long long>(m+1, 1));
        for (int i = 0; i < n; ++i) {
            long long base = nums[i] % MOD;
            for (int c = 1; c <= m; ++c) poww[i][c] = (poww[i][c-1] * base) % MOD;
        }
        int maxP = n + 30;
        vector<vector<vector<long long>>> dp(m+1, vector<vector<long long>>(m+1, vector<long long>(k+1, 0)));
        dp[0][0][0] = 1;
        for (int pos = 0; pos < maxP; ++pos) {
            vector<vector<vector<long long>>> ndp(m+1, vector<vector<long long>>(m+1, vector<long long>(k+1, 0)));
            if (pos < n) {
                for (int used = 0; used <= m; ++used) {
                    for (int carry = 0; carry <= m; ++carry) {
                        for (int ones = 0; ones <= k; ++ones) {
                            long long val = dp[used][carry][ones];
                            if (!val) continue;
                            int rem = m - used;
                            for (int c = 0; c <= rem; ++c) {
                                int s = c + carry;
                                int bit = s & 1;
                                int carry2 = s >> 1;
                                int ones2 = ones + bit;
                                if (ones2 > k) continue;
                                long long add = val;
                                add = (add * comb[rem][c]) % MOD;
                                add = (add * poww[pos][c]) % MOD;
                                ndp[used + c][carry2][ones2] += add;
                                if (ndp[used + c][carry2][ones2] >= MOD) ndp[used + c][carry2][ones2] -= MOD;
                            }
                        }
                    }
                }
            } else {
                for (int used = 0; used <= m; ++used) {
                    for (int carry = 0; carry <= m; ++carry) {
                        for (int ones = 0; ones <= k; ++ones) {
                            long long val = dp[used][carry][ones];
                            if (!val) continue;
                            int s = carry;
                            int bit = s & 1;
                            int carry2 = s >> 1;
                            int ones2 = ones + bit;
                            if (ones2 > k) continue;
                            ndp[used][carry2][ones2] += val;
                            if (ndp[used][carry2][ones2] >= MOD) ndp[used][carry2][ones2] -= MOD;
                        }
                    }
                }
            }
            dp.swap(ndp);
        }
        return (int)(dp[m][0][k] % MOD);
    }
};