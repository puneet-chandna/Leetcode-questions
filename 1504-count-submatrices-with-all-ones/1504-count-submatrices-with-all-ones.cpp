class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int ans = 0;
        vector<int> row(n);
        for (int base = 0; base < m; ++base) {
            row.assign(n, 1);
            for (int i = base; i < m; ++i) {
                for (int j = 0; j < n; ++j)
                    row[j] &= mat[i][j];
                ans += countRow(row);
            }
        }
        return ans;
    }

    int countRow(const vector<int>& row) {
        int res = 0, cnt = 0;
        for (int v : row) {
            cnt = v == 0 ? 0 : cnt + 1;
            res += cnt;
        }
        return res;
    }
};