class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int> cnt;
        for(int x : basket1) ++cnt[x];
        for(int x : basket2) --cnt[x];

        vector<int> swapList;
        int globalMin = INT_MAX;
        for (auto& [val, freq] : cnt) {
            if ((freq & 1) != 0) return -1;
            globalMin = min(globalMin, val);
            for (int c = abs(freq)/2; c > 0; --c)
                swapList.push_back(val);
        }

        if (swapList.empty()) return 0;
        sort(swapList.begin(), swapList.end());
        int half = swapList.size()/2;
        long long ans = 0;
        for (int i = 0; i < half; ++i) {
            ans += min<long long>(swapList[i], 2LL * globalMin);
        }
        return ans;
    }
};