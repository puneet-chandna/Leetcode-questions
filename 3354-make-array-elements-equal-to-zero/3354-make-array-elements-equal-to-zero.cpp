class Solution {
public:
    bool valid(vector<int> nums, int start, int dir) {
        int n = nums.size(), curr = start;
        while (curr >= 0 && curr < n) {
            if (nums[curr] == 0) curr += dir;
            else {
                nums[curr]--;
                dir = -dir;
                curr += dir;
            }
        }
        for (int x : nums) if (x != 0) return false;
        return true;
    }
    int countValidSelections(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) 
            if (nums[i] == 0) ans += valid(nums, i, 1) + valid(nums, i, -1);
        return ans;
    }
};