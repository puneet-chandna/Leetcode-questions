class Solution {
public:

typedef long long ll;
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<long long> gaps(n+1);
        gaps[0] = startTime[0];
        for (int i = 1; i < n; ++i)
            gaps[i] = startTime[i] - endTime[i-1];
        gaps[n] = eventTime - endTime[n-1];

        vector<long long> maxLeft(n+1), maxRight(n+1);
        maxLeft[0] = gaps[0];
        for (int i = 1; i <= n; ++i)
            maxLeft[i] = max(maxLeft[i-1], gaps[i]);
        maxRight[n] = gaps[n];
        for (int i = n-1; i >= 0; --i)
            maxRight[i] = max(maxRight[i+1], gaps[i]);

        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            long long d = endTime[i] - startTime[i];
            long long sum = gaps[i] + gaps[i+1];
            long long available = max(
                (i > 0 ? maxLeft[i-1] : 0LL),
                (i+2 <= n ? maxRight[i+2] : 0LL)
            );
            if (d <= available) sum += d;
            ans = max(ans, sum);
        }
        return (int)ans;
    }
};