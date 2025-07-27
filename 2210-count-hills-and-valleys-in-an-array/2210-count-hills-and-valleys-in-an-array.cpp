class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> a;
        for (int x : nums) {
            if (a.empty() || a.back() != x)
                a.push_back(x);
        }
        int ans = 0;
        int m = a.size();
        for (int i = 1; i + 1 < m; ++i) {
            if ((a[i] > a[i-1] && a[i] > a[i+1]) ||
                (a[i] < a[i-1] && a[i] < a[i+1])) {
                ans++;
            }
        }
        return ans;
    }
};