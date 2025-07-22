class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int l = 0, ans = 0, score = 0;
        for (int r = 0; r < nums.size(); ++r) {
            while (!seen.insert(nums[r]).second) {
                seen.erase(nums[l]);
                score -= nums[l++];
            }
            score += nums[r];
            ans = max(ans, score);
        }
        return ans;
        
    }
};