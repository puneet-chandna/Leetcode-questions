class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int dp[2][2] = {};
        for (int x : nums) {
            int p = x % 2;
            for (int y = 0; y < 2; ++y)
                dp[p][y] = dp[y][p] + 1;
        }
        return max({dp[0][0], dp[0][1], dp[1][0], dp[1][1]});
    }
};