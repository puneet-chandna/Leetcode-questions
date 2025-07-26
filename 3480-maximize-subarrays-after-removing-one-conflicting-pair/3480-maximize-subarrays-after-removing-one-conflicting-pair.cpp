class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        long long valid = 0;
        int maxL = 0, secondL = 0;
        vector<long long> gains(n + 2, 0);
        vector<vector<int>> conflicts(n + 2);
        for (auto& p : conflictingPairs) {
            int a = p[0], b = p[1];
            if (a > b) swap(a, b);
            conflicts[b].push_back(a);
        }
        for (int r = 1; r <= n; ++r) {
            for (int l : conflicts[r]) {
                if (l > maxL) {
                    secondL = maxL;
                    maxL = l;
                } else if (l > secondL) {
                    secondL = l;
                }
            }
            valid += r - maxL;
            gains[maxL] += maxL - secondL;
        }
        long long mx_gain = *max_element(gains.begin(), gains.end());
        return valid + mx_gain;
    }
};