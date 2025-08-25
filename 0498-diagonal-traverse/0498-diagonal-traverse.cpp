class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        if (m == 0) return {};
        int n = mat[0].size();
        vector<int> result(m * n);
        int dir = 1; 
        int row = 0, col = 0;

        for (int idx = 0; idx < m * n; ++idx) {
            result[idx] = mat[row][col];
            row -= dir;
            col += dir;

            if (row >= m)      { row = m - 1; col += 2; dir = -dir; }
            if (col >= n)      { col = n - 1; row += 2; dir = -dir; }
            if (row < 0)       { row = 0; dir = -dir; }
            if (col < 0)       { col = 0; dir = -dir; }
        }
        return result;
    }
};