class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        auto isIncreasing = [&](int l) {
            for (int i = l; i < l + k - 1; i++) {
                if (nums[i] >= nums[i + 1]) return false;
            }
            return true;
        };
        
    
        for (int i = 0; i + 2 * k <= n; i++) {
            if (isIncreasing(i) && isIncreasing(i + k))
                return true;
        }
        
        return false;
    }
};