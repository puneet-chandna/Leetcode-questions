class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1e9 + 7;
        int n = nums.size(), ans = 0;
        sort(nums.begin(), nums.end());
        vector<int> pows(n,1);
        for(int i = 1; i < n; ++i) pows[i] = (long long)pows[i-1] * 2 % MOD;
        int l = 0, r = n - 1;
        while(l <= r) {
            if(nums[l] + nums[r] <= target) {
                ans = (ans + pows[r - l]) % MOD;
                ++l;
            } else {
                --r;
            }
        }
        return ans;
        
    }
};