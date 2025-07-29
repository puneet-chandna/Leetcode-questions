class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        const int B = 30;
        vector<int> ans(n, 1), last(B, -1);
        for (int i = n - 1; i >= 0; --i) {
            int maxLen = 1;
            for (int b = 0; b < B; ++b) {
                if (nums[i] & (1 << b)) {
                    last[b] = i;
                } else if (last[b] != -1) {
                    maxLen = max(maxLen, last[b] - i + 1);
                }
            }
            ans[i] = maxLen;
        }
        return ans;
    }
};