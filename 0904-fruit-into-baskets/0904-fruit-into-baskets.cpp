class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> cnt;
        int res = 0, l = 0;
        for (int r = 0; r < fruits.size(); ++r) {
            ++cnt[fruits[r]];
            while (cnt.size() > 2) {
                if (--cnt[fruits[l]] == 0)
                    cnt.erase(fruits[l]);
                ++l;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};