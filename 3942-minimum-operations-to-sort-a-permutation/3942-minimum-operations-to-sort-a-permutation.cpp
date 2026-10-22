
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int pos = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                pos = i;
                break;
            }
        }

        bool ascending = true;
        bool descending = true;

        for (int i = 0; i < n; i++) {
            if (nums[(pos + i) % n] != i)
                ascending = false;

            if (nums[(pos - i + n) % n] != i)
                descending = false;
        }

        int ans = INT_MAX;

        if (ascending) {
            ans = min(ans, min(pos, n - pos + 2));
        }

        if (descending) {
            int left = (pos + 1) % n;
            int right = n - pos - 1;

            ans = min(ans, 1 + min(left, right));
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
