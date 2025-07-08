class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end(), [](auto &a, auto &b){
            return a[0] < b[0];
        });
        vector<long long> starts(n);
        for(int i = 0; i < n; ++i) starts[i] = events[i][0];
        vector<int> nextIdx(n);
        for(int i = 0; i < n; ++i) {
            long long endi = events[i][1];
            int j = upper_bound(starts.begin(), starts.end(), endi) - starts.begin();
            nextIdx[i] = j;
        }
        vector<vector<long long>> dp(k+1, vector<long long>(n+1, 0));
        for(int take = 1; take <= k; ++take) {
            for(int i = n-1; i >= 0; --i) {
                dp[take][i] = max(dp[take][i+1],
                                  events[i][2] + dp[take-1][ nextIdx[i] ]);
            }
        }
        return dp[k][0];
    }
};