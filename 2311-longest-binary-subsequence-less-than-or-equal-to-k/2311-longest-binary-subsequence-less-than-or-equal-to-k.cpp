class Solution {
public:
    int longestSubsequence(string s, int k) {
        int len = 0;
        long long val = 0;
        long long p = 1;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s[i] == '0') {
                len++;
            } else {
                if (val + p <= k) {
                    val += p;
                    len++;
                }
            }
            if (p < 2e9) {
                p *= 2;
            }
        }
        return len;
    }
};