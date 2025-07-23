class Solution {
public:
    int maximumGain(string s, int x, int y) {
        char c1 = 'a', c2 = 'b';
        int p1 = x, p2 = y;
        if (y > x) {
            swap(c1, c2);
            swap(p1, p2);
        }
        long long ans = 0;
        vector<char> st;
        for (char c : s) {
            st.push_back(c);
            if (st.size() >= 2 && st[st.size()-2] == c1 && st.back() == c2) {
                st.pop_back();
                st.pop_back();
                ans += p1;
            }
        }
        string rem;
        for (char c : st)
            rem.push_back(c);
        st.clear();
        for (char c : rem) {
            st.push_back(c);
            if (st.size() >= 2 && st[st.size()-2] == c2 && st.back() == c1) {
                st.pop_back();
                st.pop_back();
                ans += p2;
            }
        }
        return ans;
    }
};