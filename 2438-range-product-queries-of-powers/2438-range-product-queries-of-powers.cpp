class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
      
        constexpr int MOD = 1'000'000'007;
        vector<int> pows;
        
        for (int b = 0; b < 31; ++b) {
            if (n & (1 << b)) {
                pows.push_back(1 << b);
            }
        }
        vector<int> ans;
        ans.reserve(queries.size());
        for (auto &q : queries) {
            long prod = 1;
            for (int i = q[0]; i <= q[1]; ++i) {
                prod = (prod * pows[i]) % MOD;
            }
            ans.push_back((int)prod);
        }
        return ans;
    }
};