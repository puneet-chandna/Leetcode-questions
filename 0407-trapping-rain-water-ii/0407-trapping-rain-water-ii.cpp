
struct Cell {
    int h;
    int r;
    int c;
};

struct Cmp {
    bool operator()(const Cell &a, const Cell &b) const {
        return a.h > b.h; 
    }
};

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if (m == 0) return 0;
        int n = heightMap[0].size();
        if (m < 3 || n < 3) return 0;  

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<Cell, vector<Cell>, Cmp> pq;

        for (int i = 0; i < m; i++) {
            pq.push(Cell{heightMap[i][0], i, 0});
            pq.push(Cell{heightMap[i][n-1], i, n-1});
            visited[i][0] = visited[i][n-1] = true;
        }
        for (int j = 1; j < n-1; j++) {
            pq.push(Cell{heightMap[0][j], 0, j});
            pq.push(Cell{heightMap[m-1][j], m-1, j});
            visited[0][j] = visited[m-1][j] = true;
        }

        int total = 0;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!pq.empty()) {
            Cell cur = pq.top();
            pq.pop();
            for (auto &d : dirs) {
                int nr = cur.r + d[0];
                int nc = cur.c + d[1];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (visited[nr][nc]) continue;
                visited[nr][nc] = true;
                int nh = heightMap[nr][nc];
                if (nh < cur.h) {
                    total += (cur.h - nh);
                }
                
                pq.push(Cell{ max(cur.h, nh), nr, nc });
            }
        }

        return total;
    }
};