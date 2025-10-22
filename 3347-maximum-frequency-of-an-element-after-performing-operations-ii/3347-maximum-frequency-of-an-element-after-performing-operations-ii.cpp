class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<long long,int> cnt;
        map<long long,int> diff;
        for (auto &v : nums) {
            cnt[v]++;
            diff[v - k]++;
            diff[v + k + 1]--;
            diff[v] += 0;
        }
        long long s = 0;
        int ans = 0;
        for (auto &p : diff) {
            long long x = p.first;
            s += p.second;
            int already = cnt.count(x) ? cnt[x] : 0;
            long long possible = min(s, (long long)already + numOperations);
            ans = max(ans, (int)possible);
        }
        return ans;
    }
};