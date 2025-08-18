class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return dfs(nums);
    }

    bool dfs(vector<double>& nums) {
        if (nums.size() == 1) {
            return fabs(nums[0] - 24.0) < 1e-3;
        }
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                vector<double> next;
                for (int k = 0; k < n; ++k) {
                    if (k != i && k != j)
                        next.push_back(nums[k]);
                }
                for (double res : generate(nums[i], nums[j])) {
                    next.push_back(res);
                    if (dfs(next)) return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }

    vector<double> generate(double a, double b) {
        vector<double> res = {a + b, a - b, b - a, a * b};
        if (fabs(b) > 1e-6) res.push_back(a / b);
        if (fabs(a) > 1e-6) res.push_back(b / a);
        return res;
    }
    
};