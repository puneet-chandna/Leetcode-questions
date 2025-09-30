class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        for (int sz = n; sz > 1; --sz) {
            for (int i = 0; i + 1 < sz; ++i) {
                nums[i] = (nums[i] + nums[i+1]) % 10;
            }
        }
        return nums[0];
    }
};