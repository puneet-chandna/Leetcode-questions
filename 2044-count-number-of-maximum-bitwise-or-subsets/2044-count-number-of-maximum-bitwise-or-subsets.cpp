class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int target = accumulate(nums.begin(), nums.end(), 0, bit_or<>());
        int count = 0;
        dfs(nums, 0, 0, target, count);
        return count;
    }
private:
    void dfs(const vector<int>& nums, int i, int curr, int target, int& count) {
        if (i == nums.size()) {
            if (curr == target) ++count;
            return;
        }
        dfs(nums, i + 1, curr, target, count);
        dfs(nums, i + 1, curr | nums[i], target, count);
        
    }
};