class Solution {
public:
    int findKthNumber(int n, int k) {
        long curr = 1;
        k--;
        
        while (k > 0) {
            long steps = countSteps(n, curr, curr + 1);
            if (steps <= k) {
                curr++;
                k -= steps;
            } else {
                curr *= 10;
                k--;
            }
        }
        
        return curr;
    }
    
private:
    long countSteps(int n, long curr, long next) {
        long steps = 0;
        while (curr <= n) {
            steps += min((long)n + 1, next) - curr;
            curr *= 10;
            next *= 10;
        }
        return steps;
    }
};