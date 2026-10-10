class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = 1LL * k1 + k2;
        vector<int> diff(n);
        int maxDiff = 0;
        long long total = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxDiff = max(maxDiff, diff[i]);
            total += diff[i];
        }

        if (k >= total) return 0;

        int low = 0, high = maxDiff;
        while (low < high) {
            int mid = low + (high - low) / 2;
            long long needed = 0;

            for (int d : diff) {
                if (d > mid) needed += d - mid;
            }

            if (needed <= k)
                high = mid;
            else
                low = mid + 1;
        }

        int level = low;
        long long needed = 0;
        long long ans = 0;

        for (int d : diff) {
            needed += max(0, d - level);
            long long reduced = min(d, level);
            ans += reduced * reduced;
        }
        long long remaining = k - needed;
        ans -= remaining * (2LL * level - 1);

        return ans;
    }
};