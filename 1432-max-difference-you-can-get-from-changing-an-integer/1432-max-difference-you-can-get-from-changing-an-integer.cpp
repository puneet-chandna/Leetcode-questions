class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        
        string maxStr = s;
        for (char c : s) {
            if (c != '9') {
                for (char& ch : maxStr) {
                    if (ch == c) ch = '9';
                }
                break;
            }
        }
        
        string minStr = s;
        if (s[0] != '1') {
            char target = s[0];
            for (char& ch : minStr) {
                if (ch == target) ch = '1';
            }
        } else {
            for (int i = 1; i < s.length(); i++) {
                if (s[i] != '0' && s[i] != '1') {
                    char target = s[i];
                    for (char& ch : minStr) {
                        if (ch == target) ch = '0';
                    }
                    break;
                }
            }
        }
        
        return stoi(maxStr) - stoi(minStr);
    }
};