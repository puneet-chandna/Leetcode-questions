class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, ans = 0;
        for (auto& row : bank) {
            int cnt = count(row.begin(), row.end(), '1');
            if (cnt) {
                ans += prev * cnt;
                prev = cnt;
            }
        }
        return ans;
    }
};