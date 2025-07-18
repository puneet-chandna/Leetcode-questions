class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
         int n = nums.size() / 3;
        vector<long long> minLeft(nums.size());
        priority_queue<long long> leftHeap;
        long long ls = 0;
        for (int i = 0; i < 2 * n; ++i) {
            leftHeap.push(nums[i]);
            ls += nums[i];
            if (leftHeap.size() > n) {
                ls -= leftHeap.top();
                leftHeap.pop();
            }
            if (leftHeap.size() == n) minLeft[i] = ls;
        }
        priority_queue<long long, vector<long long>, greater<long long>> rightHeap;
        long long rs = 0, ans = LLONG_MAX;
        for (int i = nums.size() - 1; i >= n; --i) {
            rightHeap.push(nums[i]);
            rs += nums[i];
            if (rightHeap.size() > n) {
                rs -= rightHeap.top();
                rightHeap.pop();
            }
            if (rightHeap.size() == n) {
                ans = min(ans, minLeft[i - 1] - rs);
            }
        }
        return ans;
    }
};