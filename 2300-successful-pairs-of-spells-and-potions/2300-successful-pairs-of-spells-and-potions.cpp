class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            long long s = spells[i];
            int idx = firstIndexSuccess(s, potions, success);
           
            ans[i] = m - idx;
        }
        return ans;
    }

private:
    int firstIndexSuccess(long long spell, vector<int>& potions, long long success) {
        int l = 0, r = potions.size();  
        while (l < r) {
            int mid = l + (r - l) / 2;
            long long prod = spell * potions[mid];
            if (prod >= success) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};