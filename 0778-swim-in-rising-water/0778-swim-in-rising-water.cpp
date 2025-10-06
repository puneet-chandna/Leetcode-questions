class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
    const int INF = 1e9;
    vector<int> dr = {1,-1,0,0}, dc = {0,0,1,-1};
    vector<vector<int>> dist(n, vector<int>(n, INF));
  
    using T = tuple<int,int,int>;
    priority_queue<T, vector<T>, greater<T>> pq;

    dist[0][0] = grid[0][0];
    pq.emplace(dist[0][0], 0, 0);

    while (!pq.empty()) {
        auto [d, r, c] = pq.top(); pq.pop();
        if (d != dist[r][c]) continue; 
        if (r == n-1 && c == n-1) return d; 
        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
            int nd = max(d, grid[nr][nc]);
            if (nd < dist[nr][nc]) {
                dist[nr][nc] = nd;
                pq.emplace(nd, nr, nc);
            }
        }
    }
    return -1;
    }
};