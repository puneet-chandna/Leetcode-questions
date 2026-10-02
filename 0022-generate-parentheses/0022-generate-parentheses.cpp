class Solution {
public:
    void solve(int n, int open, int close, string curr,
               vector<string>& ans) {

        // We have used all parentheses
        if (open == n && close == n) {
            ans.push_back(curr);
            return;
        }

        // Add '('
        if (open < n) {
            solve(n, open + 1, close, curr + '(', ans);
        }

        // Add ')'
        if (close < open) {
            solve(n, open, close + 1, curr + ')', ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        solve(n, 0, 0, "", ans);

        return ans;
        
    }
};