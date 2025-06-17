class Solution {
public:
    int countGoodArrays(int n, int m, int k) {
        const auto [fact, invFact] = getFactAndInvFact(n);
        return (long long)m * modPow(m - 1, n - k - 1) % kMod * nCk(n - 1, k, fact, invFact) % kMod;
    }
    
private:
    static constexpr int kMod = 1000000007;
    
    long long modPow(long long x, long long n) {
        if (n == 0) return 1;
        if (n % 2 == 1) return x * modPow(x % kMod, n - 1) % kMod;
        return modPow(x * x % kMod, n / 2) % kMod;
    }
    
    pair<vector<long long>, vector<long long>> getFactAndInvFact(int n) {
        vector<long long> fact(n + 1);
        vector<long long> invFact(n + 1);
        vector<long long> inv(n + 1);
        
        fact[0] = invFact[0] = 1;
        inv[0] = inv[1] = 1;
        
        for (int i = 1; i <= n; ++i) {
            if (i >= 2) {
                inv[i] = kMod - kMod / i * inv[kMod % i] % kMod;
            }
            fact[i] = fact[i - 1] * i % kMod;
            invFact[i] = invFact[i - 1] * inv[i] % kMod;
        }
        
        return {fact, invFact};
    }
    
    int nCk(int n, int k, const vector<long long>& fact, const vector<long long>& invFact) {
        return fact[n] * invFact[k] % kMod * invFact[n - k] % kMod;
        
    }
};