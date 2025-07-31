class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans, cur;
        for (int x : arr) {
            unordered_set<int> nxt;
            nxt.insert(x);
            for (int y : cur) {
                nxt.insert(x | y);
            }
            cur = move(nxt);
            ans.insert(cur.begin(), cur.end());
        }
        return ans.size();
    }
};