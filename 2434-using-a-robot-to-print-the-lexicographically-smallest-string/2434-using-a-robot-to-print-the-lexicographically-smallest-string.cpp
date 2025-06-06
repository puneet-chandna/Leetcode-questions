class Solution {
public:
    string robotWithString(string s) {
        vector<int> cnt(26, 0);
        for (char& c : s) ++cnt[c - 'a'];
        char mi = 'a';
        string stk;
        string ans;
        for (char& c : s) {
            --cnt[c - 'a'];
            while (mi < 'z' && cnt[mi - 'a'] == 0) ++mi;
            stk.push_back(c);
            while (!stk.empty() && stk.back() <= mi) {
                ans.push_back(stk.back());
                stk.pop_back();
            }
        }
        return ans;
    }
};