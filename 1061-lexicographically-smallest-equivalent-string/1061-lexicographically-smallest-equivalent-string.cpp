class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> parent(26);
      
        for (int i = 0; i < 26; ++i) {
            parent[i] = i;
        }

        function<int(int)> find = [&](int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        };

        auto unite = [&](int x, int y) {
            int px = find(x);
            int py = find(y);
            if (px == py) return;
            if (px < py) {
                parent[py] = px;
            } else {
                parent[px] = py;
            }
        };

    
        for (int i = 0; i < s1.size(); ++i) {
            unite(s1[i] - 'a', s2[i] - 'a');
        }

        string result;
        for (char c : baseStr) {
            result += char(find(c - 'a') + 'a');
        }

        return result;
    }
};