class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, -1);
        unordered_map<int,int> lastRain;   
        set<int> dryDays;                   

        for (int i = 0; i < n; i++) {
            int v = rains[i];
            if (v > 0) {
              
                if (lastRain.count(v)) {
                    int prevDay = lastRain[v];
                    auto it = dryDays.upper_bound(prevDay);
                    if (it == dryDays.end()) {
                   
                        return {};
                    }
                    int dryDay = *it;
                    ans[dryDay] = v;
                    dryDays.erase(it);
                }
         
                lastRain[v] = i;
               
            } else {
                dryDays.insert(i);
              
                ans[i] = 1;
            }
        }
        return ans;
    }
};