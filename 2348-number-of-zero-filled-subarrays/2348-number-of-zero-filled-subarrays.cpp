class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long total = 0, count = 0;
        for (int v : nums) {
            if (v == 0) {
                ++count;
            } else {
                count = 0;
            }
            total += count;
        }
        return total;
    }
};