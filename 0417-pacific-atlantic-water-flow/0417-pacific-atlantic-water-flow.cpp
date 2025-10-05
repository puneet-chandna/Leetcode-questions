class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        if (m == 0) return {};
        int n = heights[0].size();
        vector<vector<bool>> reachP(m, vector<bool>(n, false));
        vector<vector<bool>> reachA(m, vector<bool>(n, false));

        queue<pair<int,int>> qP, qA;

        for (int i = 0; i < m; i++) {
            reachP[i][0] = true;
            qP.push({i, 0});
        }
        for (int j = 0; j < n; j++) {
            reachP[0][j] = true;
            qP.push({0, j});
        }

        for (int i = 0; i < m; i++) {
            reachA[i][n - 1] = true;
            qA.push({i, n - 1});
        }
        for (int j = 0; j < n; j++) {
            reachA[m - 1][j] = true;
            qA.push({m - 1, j});
        }

        const int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

        auto bfs = [&](queue<pair<int,int>>& q, vector<vector<bool>>& reach) {
            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();
                int h = heights[r][c];
                for (auto &d : dirs) {
                    int nr = r + d[0];
                    int nc = c + d[1];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    if (reach[nr][nc]) continue;
                    if (heights[nr][nc] < h) continue;
                    reach[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        };

        bfs(qP, reachP);
        bfs(qA, reachA);

        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (reachP[i][j] && reachA[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};