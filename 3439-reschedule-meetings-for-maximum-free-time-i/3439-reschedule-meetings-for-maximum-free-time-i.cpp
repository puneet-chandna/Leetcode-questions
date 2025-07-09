class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
         int n = startTime.size();
        vector<long long> dur(n), prefix(n+1, 0);
        for (int i = 0; i < n; ++i) {
            dur[i] = (long long)endTime[i] - startTime[i];
            prefix[i+1] = prefix[i] + dur[i];
        }
        long long best = (long long)startTime[0] - 0LL;
        for (int i = 1; i < n; ++i)
            best = max(best, (long long)startTime[i] - endTime[i-1]);
        best = max(best, eventTime - (long long)endTime[n-1]);
        if (k == 0) return best;

        for (int R = k-1; R < n; ++R) {
            int L = R - k + 1;
            long long totalDur = prefix[R+1] - prefix[L];
            long long prevEnd = (L > 0 ? endTime[L-1] : 0LL);
            long long nextStart = (R+1 < n ? startTime[R+1] : eventTime);
            long long freeInterval = nextStart - totalDur - prevEnd;
            best = max(best, freeInterval);
        }
        return best;
    }
};