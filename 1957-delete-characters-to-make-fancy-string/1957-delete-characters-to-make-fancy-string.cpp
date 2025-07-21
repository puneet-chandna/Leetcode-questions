class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        for (char c : s) {
            if (ans.size() < 2 || ans.back() != c || ans[ans.size() - 2] != c)
                ans.push_back(c);
        }
        return ans;
    }
};