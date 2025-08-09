class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
    double x = log2(n);
    return floor(x) == x;
    }
};