class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (long k = 0; k <= 60; ++k) {
            long target = num1 - k * 1LL * num2;
            if (target >= k && __builtin_popcountl(target) <= k) {
                return (int)k;
            }
        }
        return -1;
    }
};