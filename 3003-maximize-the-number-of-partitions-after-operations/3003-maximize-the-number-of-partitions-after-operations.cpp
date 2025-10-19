class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        int n = s.size();
        unordered_map<long long, int> memo;
        return dfs(s, 0, 0, true, k, memo) + 1;
    }

private:
    int dfs(const string &s, int i, int mask, bool canChange,
            int k, unordered_map<long long,int> &memo) {
        int n = s.size();
        if (i >= n) {
            return 0;  
        }
        
        long long key = ((long long)i << 32) | ((long long)mask << 1) | (canChange ? 1 : 0);
        if (memo.count(key)) return memo[key];

        int best = 0;
        int bit = 1 << (s[i] - 'a');
       
        best = max(best, processNext(s, i, mask, bit, canChange, k, memo));

        if (canChange) {
            for (int c = 0; c < 26; ++c) {
                int newBit = 1 << c;
                if (newBit == bit) continue;
                best = max(best, processNext(s, i, mask, newBit, false, k, memo));
            }
        }
        memo[key] = best;
        return best;
    }

   
    int processNext(const string &s, int i, int mask, int nextBit,
                    bool nextCanChange, int k,
                    unordered_map<long long,int> &memo) {
        int newMask = mask | nextBit;
        if (__builtin_popcount(newMask) > k) {
            return 1 + dfs(s, i+1, nextBit, nextCanChange, k, memo);
        } else {
           
            return dfs(s, i+1, newMask, nextCanChange, k, memo);
        }
    }
};