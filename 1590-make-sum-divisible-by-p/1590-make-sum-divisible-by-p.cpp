class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        for (int x : nums) total += x;
        int need = total % p;
        if (need == 0) return 0;
        unordered_map<int,int> last;
        last[0] = -1;
        int cur = 0, res = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            cur = (cur + nums[i]) % p;
            int target = (cur - need + p) % p;
            if (last.count(target)) {
                res = min(res, i - last[target]);
            }
            last[cur] = i;
        }
        if (res == nums.size()) return -1;
        return res;
    }
};