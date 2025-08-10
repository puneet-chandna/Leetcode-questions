class Solution {
public:
    bool reorderedPowerOf2(int n) {
        auto cnt = digitCount(n);
        for (int i = 0; i < 31; ++i) {
            if (digitCount(1 << i) == cnt) return true;
        }
        return false;

    }
    vector<int> digitCount(int x) {
        vector<int> count(10, 0);
        while (x > 0) {
            count[x % 10]++;
            x /= 10;
        }
        return count;
    }
};