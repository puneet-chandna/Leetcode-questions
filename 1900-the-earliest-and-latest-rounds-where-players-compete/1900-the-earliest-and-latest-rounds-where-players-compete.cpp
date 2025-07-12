class Solution {
    vector<vector<vector<pair<int,int>>>> memo;
    
    pair<int,int> solve(int l, int r, int k) {
        if (l > r) return solve(r, l, k);
        if (l == r) return {1, 1};
        auto &res = memo[l][r][k];
        if (res.first) return res;
        
        int earliest = INT_MAX, latest = INT_MIN;
        int half = (k + 1) / 2;
        
        for (int i = 1; i <= l; ++i) {
            for (int j = l - i + 1; j <= r - i; ++j) {
                int sum = i + j;
                if (sum < (l + r - k/2) || sum > half) continue;
                auto [e, L] = solve(i, j, half);
                earliest = min(earliest, e + 1);
                latest   = max(latest,   L + 1);
            }
        }
        
        return res = {earliest, latest};
    }
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        int l = firstPlayer;
        int r = n - secondPlayer + 1;
        memo.assign(n+1, vector<vector<pair<int,int>>>(n+1, vector<pair<int,int>>(n+1)));
        auto [e, L] = solve(l, r, n);
        return {e, L};
    }
};