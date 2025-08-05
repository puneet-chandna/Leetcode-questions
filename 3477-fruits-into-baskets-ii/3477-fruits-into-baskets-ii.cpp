class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size(), ans = n;
        vector<bool> used(n, false);
        for (int f : fruits) {
            for (int i = 0; i < n; ++i) {
                if (!used[i] && baskets[i] >= f) {
                    used[i] = true;
                    --ans;
                    break;
                }
            }
        }
        return ans;
    }
};