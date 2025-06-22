class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n = s.length();

        for (int i = 0; i < n; i += k) {
            string current_group = s.substr(i, k);
            if (current_group.length() < k) {
                current_group += string(k - current_group.length(), fill);
            }
            ans.push_back(current_group);
        }

        return ans;
    }
};