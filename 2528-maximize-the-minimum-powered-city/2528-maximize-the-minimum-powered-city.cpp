class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long> diff(n + 1, 0), init(n, 0);
        for (int i = 0; i < n; ++i) {
            int lo = max(0, i - r);
            int hi = min(n - 1, i + r);
            diff[lo] += stations[i];
            diff[hi + 1] -= stations[i];
        }
        long long curr = 0;
        for (int i = 0; i < n; ++i) {
            curr += diff[i];
            init[i] = curr;
        }
        
        auto can = [&](long long target) {
            vector<long long> add(n + 1, 0);
            long long extra = 0, used = 0;
            for (int i = 0; i < n; ++i) {
                extra += add[i];
                long long power = init[i] + extra;
                if (power < target) {
                    long long need = target - power;
                    if (used + need > k) return false;
                    used += need;
                    int pos = min(n - 1, i + r);
                    int lo = max(0, pos - r);
                    int hi = min(n - 1, pos + r);
                    add[lo] += need;
                    add[hi + 1] -= need;
                    extra += need;
                }
            }
            return true;
        };
        
        long long lo = 0, hi = 1LL << 40;
        while (lo < hi) {
            long long mid = (lo + hi + 1) >> 1;
            if (can(mid)) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }
};