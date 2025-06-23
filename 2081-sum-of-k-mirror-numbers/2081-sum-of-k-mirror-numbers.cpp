class Solution {
public:
    string convertToBase(long long num, int base) {
        if (num == 0) return "0";
        string res = "";
        while (num > 0) {
            res += (num % base) + '0';
            num /= base;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    bool isPalindrome(const string& s) {
        string reversed_s = s;
        reverse(reversed_s.begin(), reversed_s.end());
        return s == reversed_s;
    }

    long long kMirror(int k, int n) {
        long long total_sum = 0;
        int count_found = 0;
        int len = 1;

        while (count_found < n) {
            long long half_len = (len + 1) / 2;
            long long start = pow(10, half_len - 1);
            long long end = pow(10, half_len);

            for (long long i = start; i < end; ++i) {
                string s_half = to_string(i);
                string s_second_half = s_half;

                if (len % 2 != 0) {
                    s_second_half.pop_back();
                }
                
                reverse(s_second_half.begin(), s_second_half.end());
                
                string s_palindrome = s_half + s_second_half;
                long long num = stoll(s_palindrome);

                if (isPalindrome(convertToBase(num, k))) {
                    total_sum += num;
                    count_found++;
                    if (count_found == n) {
                        return total_sum;
                    }
                }
            }
            len++;
        }
        
        return total_sum;
    
    }
};