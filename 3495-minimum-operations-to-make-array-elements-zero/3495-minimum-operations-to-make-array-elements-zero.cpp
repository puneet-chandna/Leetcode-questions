class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for (auto &qr : queries) {
            int l = qr[0], r = qr[1];
            long long totalDigits = S(r) - S(l - 1);
            ans += (totalDigits + 1) / 2; 
        }
        return ans;
    }
    long long S(long long n) {
        if (n <= 0) return 0;
        long long res = 0;
        long long power = 1;
        int digits = 0;
        while (power <= n) {
            ++digits;
            long long blockL = power;
            long long blockR = min(n, power * 4 - 1);
            res += (blockR - blockL + 1) * 1LL * digits;
            if (power > (long long)4e18 / 4) break; 
            power *= 4;
        }
        return res;
    }
};


    