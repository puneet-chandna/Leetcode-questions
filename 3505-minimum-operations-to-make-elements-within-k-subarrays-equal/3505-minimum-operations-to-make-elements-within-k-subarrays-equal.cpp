
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        const long long INF = LLONG_MAX / 4;

        vector<long long> cost(n - x + 1);

        multiset<int> left, right;
        long long sumLeft = 0, sumRight = 0;

        auto balance = [&]() {
            while (left.size() < right.size()) {
                int v = *right.begin();
                right.erase(right.begin());
                sumRight -= v;

                left.insert(v);
                sumLeft += v;
            }

            while (left.size() > right.size() + 1) {
                auto it = prev(left.end());
                int v = *it;
                left.erase(it);
                sumLeft -= v;

                right.insert(v);
                sumRight += v;
            }
        };

        auto add = [&](int v) {
            if (left.empty() || v <= *left.rbegin()) {
                left.insert(v);
                sumLeft += v;
            } else {
                right.insert(v);
                sumRight += v;
            }
            balance();
        };

        auto remove = [&](int v) {
            auto it = left.find(v);

            if (it != left.end()) {
                left.erase(it);
                sumLeft -= v;
            } else {
                it = right.find(v);
                right.erase(it);
                sumRight -= v;
            }
            balance();
        };

        auto getCost = [&]() -> long long {
            long long median = *left.rbegin();

            return median * (long long)left.size() - sumLeft
                 + sumRight - median * (long long)right.size();
        };

        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {
                cost[i - x + 1] = getCost();
            }
        }

        vector<long long> prevDP(n + 1, 0);
        vector<long long> currDP(n + 1, INF);

        for (int j = 1; j <= k; j++) {
            fill(currDP.begin(), currDP.end(), INF);

            for (int i = 1; i <= n; i++) {
           
                currDP[i] = currDP[i - 1];

                if (i >= x && prevDP[i - x] != INF) {
                    currDP[i] = min(
                        currDP[i],
                        prevDP[i - x] + cost[i - x]
                    );
                }
            }

            prevDP.swap(currDP);
        }

        return prevDP[n];
    }
};
