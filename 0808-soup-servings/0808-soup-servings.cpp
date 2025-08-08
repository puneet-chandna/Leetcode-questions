class Solution {
public:
    double soupServings(int n) {
        if (n >= 4800) return 1.0; 
        int k = (n + 24) / 25;
        memo.assign(k + 1, vector<double>(k + 1, -1.0));
        return dfs(k, k);
    }

private:
    vector<vector<double>> memo;
    double dfs(int a, int b) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1.0;
        if (b <= 0) return 0.0;
        double &res = memo[a][b];
        if (res >= 0) return res;
        res = 0.25 * (
            dfs(a - 4, b) +
            dfs(a - 3, b - 1) +
            dfs(a - 2, b - 2) +
            dfs(a - 1, b - 3)
        );
        return res;
    }
};