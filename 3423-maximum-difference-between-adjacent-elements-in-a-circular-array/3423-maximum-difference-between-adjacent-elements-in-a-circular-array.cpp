class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxDiff = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int diff = abs(nums[i] - nums[(i + 1) % n]);
            maxDiff = max(maxDiff, diff);
        }
        
        return maxDiff;
    }
};