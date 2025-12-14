class Solution {
public:
    int numberOfWays(string corridor) {
        constexpr long long MOD = 1000000007LL;
        long long ans = 1;
        int prevSeat = -1;
        int numSeats = 0;

        for (int i = 0; i < corridor.size(); ++i) {
            if (corridor[i] == 'S') {
                ++numSeats;
      
                if (numSeats > 2 && numSeats % 2 == 1) {
                    ans = (ans * (i - prevSeat)) % MOD;
                }
                prevSeat = i;
            }
        }

        if (numSeats < 2 || (numSeats % 2 != 0)) {
            return 0;
        }
        return (int)ans;
    }
};