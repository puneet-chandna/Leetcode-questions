class Solution {
public:
    bool isPowerOfFour(int n) {
        constexpr unsigned mask = 0x55555555; 
    return n > 0 && (n & (n - 1)) == 0 && (n & mask) != 0;
    }
};