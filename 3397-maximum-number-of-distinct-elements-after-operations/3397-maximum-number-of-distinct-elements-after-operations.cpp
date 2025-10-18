class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        long long occupied = LLONG_MIN;  
        
        for (long long x : nums) {
            if (occupied < x + k) {
                long long newValue = max(occupied + 1, x - k);
             
                if (newValue <= x + k) {
                    occupied = newValue;
                    ++ans;
                }
            }
        }
        return (int)ans;
    }
};