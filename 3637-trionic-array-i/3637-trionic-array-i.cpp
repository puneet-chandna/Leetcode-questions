class Solution {
public:
    bool isTrionic(vector<int>& nums) {
         int n = nums.size();
        int i = 0;

        // Phase 1: strictly increasing
        while (i < n - 2 && nums[i] < nums[i + 1]) {
            i++;
        }

        // Must have at least one increase
        if (i == 0) return false;

        // Phase 2: strictly decreasing
        int j = i;
        while (j < n - 1 && nums[j] > nums[j + 1]) {
            j++;
        }

        // Must have a decrease and room for final increase
        if (j == i || j == n - 1) return false;

        // Phase 3: strictly increasing again
        while (j < n - 1 && nums[j] < nums[j + 1]) {
            j++;
        }

        // If we reach end, it's trionic
        return j == n - 1;
    }
};