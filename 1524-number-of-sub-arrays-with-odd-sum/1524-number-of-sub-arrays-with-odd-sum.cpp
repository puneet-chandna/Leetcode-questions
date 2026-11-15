
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;

        long long even = 1, odd = 0;
        long long ans = 0;
        int sum = 0;

        for (int x : arr) {
            sum = (sum + x) % 2;

            if (sum == 0) {
                ans = (ans + odd) % MOD;
                even++;
            } else {
                ans = (ans + even) % MOD;
                odd++;
            }
        }

        return ans;
    }
};
