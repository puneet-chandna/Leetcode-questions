class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<long long,int> cnt;
        for (int &v : power) {
            cnt[v]++;
        }
        vector<pair<long long,int>> a;
        a.reserve(cnt.size());
        for (auto &pr : cnt) {
            a.emplace_back(pr.first, pr.second);
        }
        sort(a.begin(), a.end());
        int n = a.size();
        vector<long long> dp(n+1, 0);

        vector<long long> dam(n);
        for (int i = 0; i < n; i++) dam[i] = a[i].first;

        for (int i = 1; i <= n; i++) {
           
            dp[i] = dp[i-1];
            long long p = a[i-1].first;
            int c = a[i-1].second;
           
            long long target = p - 3;
            int j = upper_bound(dam.begin(), dam.begin() + (i-1), target) - dam.begin();
            
            long long candidate = (long long)p * c;
            candidate += dp[j];
            dp[i] = max(dp[i], candidate);
        }
        return dp[n];
    }
};