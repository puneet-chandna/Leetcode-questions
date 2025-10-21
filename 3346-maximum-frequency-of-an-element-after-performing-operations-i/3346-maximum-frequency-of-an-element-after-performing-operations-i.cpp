class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int,int> cnt;
        map<long long,int> diff;
        for(int v: nums) {
            cnt[v]++;
            diff[(long long)v - k]++;
            diff[(long long)v + k + 1]--;
            diff[v] += 0;
        }
        long long s = 0;
        int ans = 0;
        for(auto &p : diff) {
            long long x = p.first;
            s += p.second;
            int already = cnt.count(x) ? cnt[x] : 0;
            long long convertible = s;
            long long achievable = min(convertible, already + (long long)numOperations);
            ans = max(ans, (int)achievable);
        }
        return ans;
    }
};