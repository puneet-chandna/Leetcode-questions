class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long total = 0;
        
        for (int i = 0; i <= min(n, limit); i++) {
            int remaining = n - i;
            if (remaining > 2 * limit) continue;
            
            int maxJ = min(remaining, limit);
            int minJ = max(0, remaining - limit);
            
            if (maxJ >= minJ) {
                total += maxJ - minJ + 1;
            }
        }
        
        return total;
    }
};