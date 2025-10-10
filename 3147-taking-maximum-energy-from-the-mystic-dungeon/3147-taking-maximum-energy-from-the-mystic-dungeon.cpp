class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        long long ans = LLONG_MIN;
        int n = energy.size();
        for (int i = n - k; i < n; i++) {
            long long s = 0;
            for (int j = i; j >= 0; j -= k) {
                s += energy[j];
                ans = max(ans, s);
            }
        }
        return ans;
    }
};