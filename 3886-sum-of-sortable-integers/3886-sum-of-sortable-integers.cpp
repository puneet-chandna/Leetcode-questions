
class Solution {
public:
    bool canSort(vector<int>& nums, int k) {
        int n = nums.size();
        int prevMax = INT_MIN;
        for (int i = 0; i < n; i += k) {
            int mn = INT_MAX, mx = INT_MIN;
            int descents = 0;
            for (int j = i; j < i + k; j++) {
                int next = (j + 1 == i + k) ? i : j + 1;
                if (nums[j] > nums[next])
                    descents++;
                mn = min(mn, nums[j]);
                mx = max(mx, nums[j]);
            }
            if (descents > 1)
                return false;
            if (prevMax > mn)
                return false;
            prevMax = mx;
        }

        return true;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k * k <= n; k++) {
            if (n % k != 0) continue;

            if (canSort(nums, k))
                ans += k;
            int other = n / k;
            if (other != k && canSort(nums, other))
                ans += other;
        }

        return ans;
    }
};
