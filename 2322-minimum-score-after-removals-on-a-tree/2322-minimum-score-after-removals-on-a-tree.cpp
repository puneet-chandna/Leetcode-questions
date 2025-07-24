class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        
        int n = nums.size();
        vector<vector<int>> adj(n);
        
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> subtreeXor(n);
        vector<int> parent(n, -1);
        
        function<void(int, int)> dfs = [&](int u, int p) {
            parent[u] = p;
            subtreeXor[u] = nums[u];
            for (int v : adj[u]) {
                if (v != p) {
                    dfs(v, u);
                    subtreeXor[u] ^= subtreeXor[v];
                }
            }
        };
        
        dfs(0, -1);
        
        int totalXor = subtreeXor[0];
        int minScore = INT_MAX;
        
        auto isAncestor = [&](int a, int b) -> bool {
            int curr = b;
            while (curr != -1) {
                if (curr == a) return true;
                curr = parent[curr];
            }
            return false;
        };
        
        for (int i = 0; i < edges.size(); i++) {
            for (int j = i + 1; j < edges.size(); j++) {
                int u1 = edges[i][0], v1 = edges[i][1];
                int u2 = edges[j][0], v2 = edges[j][1];
                
                if (parent[u1] == v1) swap(u1, v1);
                if (parent[u2] == v2) swap(u2, v2);
                
                int xor1, xor2, xor3;
                
                if (isAncestor(v1, v2)) {
                    xor1 = subtreeXor[v2];
                    xor2 = subtreeXor[v1] ^ subtreeXor[v2];
                    xor3 = totalXor ^ subtreeXor[v1];
                } else if (isAncestor(v2, v1)) {
                    xor1 = subtreeXor[v1];
                    xor2 = subtreeXor[v2] ^ subtreeXor[v1];
                    xor3 = totalXor ^ subtreeXor[v2];
                } else {
                    xor1 = subtreeXor[v1];
                    xor2 = subtreeXor[v2];
                    xor3 = totalXor ^ xor1 ^ xor2;
                }
                
                vector<int> xors = {xor1, xor2, xor3};
                sort(xors.begin(), xors.end());
                minScore = min(minScore, xors[2] - xors[0]);
            }
        }
        
        return minScore;
    }
};