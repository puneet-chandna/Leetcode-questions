struct T {
    long long endTime;
    int roomId;
};
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
         vector<int> count(n);
        sort(meetings.begin(), meetings.end());
        auto cmp = [](const T &a, const T &b) {
            if (a.endTime != b.endTime) return a.endTime > b.endTime;
            return a.roomId > b.roomId;
        };
        priority_queue<T, vector<T>, decltype(cmp)> busy(cmp);
        priority_queue<int, vector<int>, greater<int>> freeRooms;
        for (int i = 0; i < n; ++i) freeRooms.push(i);

        for (auto &m : meetings) {
            int start = m[0], end = m[1];
            while (!busy.empty() && busy.top().endTime <= start) {
                freeRooms.push(busy.top().roomId);
                busy.pop();
            }
            if (freeRooms.empty()) {
                T t = busy.top(); busy.pop();
                count[t.roomId]++;
                busy.push({t.endTime + (end - start), t.roomId});
            } else {
                int r = freeRooms.top(); freeRooms.pop();
                count[r]++;
                busy.push({end, r});
            }
        }

        return max_element(count.begin(), count.end()) - count.begin();
    }
};