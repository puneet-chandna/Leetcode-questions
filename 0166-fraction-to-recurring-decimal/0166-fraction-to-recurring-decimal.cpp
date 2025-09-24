class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string ans;
        // sign
        if ((numerator < 0) ^ (denominator < 0)) ans.push_back('-');
        // use long long to avoid overflow
        long long n = llabs((long long)numerator);
        long long d = llabs((long long)denominator);
        // integer part
        ans += to_string(n / d);
        long long rem = n % d;
        if (rem == 0) {
            return ans;
        }
        ans.push_back('.');
        unordered_map<long long, int> remPos;
        while (rem != 0) {
            if (remPos.count(rem)) {
                int pos = remPos[rem];
                ans.insert(pos, "(");
                ans.push_back(')');
                break;
            }
            remPos[rem] = ans.size();
            rem *= 10;
            long long digit = rem / d;
            ans += to_string(digit);
            rem %= d;
        }
        return ans;
    }
};