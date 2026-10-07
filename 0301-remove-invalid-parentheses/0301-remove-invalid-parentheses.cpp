class Solution {
public:
    vector<string> ans;

    bool isValid(string s) {
        int balance = 0;
        for (char c : s) {
            if (c == '(')
                balance++;
            else if (c == ')') {
                balance--;
                if (balance < 0)
                    return false;
            }
        }

        return balance == 0;
    }

    void dfs(string& s, int index, int leftRemove, int rightRemove) {

        if (leftRemove == 0 && rightRemove == 0) {
            if (isValid(s)) ans.push_back(s);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (i > index && s[i] == s[i - 1]) continue;

            if (s[i] != '(' && s[i] != ')') continue;

            char removed = s[i];
            s.erase(s.begin() + i);

            if (removed == '(' && leftRemove > 0) dfs(s, i, leftRemove - 1, rightRemove);
            
            else if (removed == ')' && rightRemove > 0)  dfs(s, i, leftRemove, rightRemove - 1);
            
            s.insert(s.begin() + i, removed);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int leftRemove = 0;
        int rightRemove = 0;
        for (char c : s) {

            if (c == '(') {
                leftRemove++;
            }
            else if (c == ')') {

                if (leftRemove > 0)leftRemove--;
                else rightRemove++;
            }
        }

        dfs(s, 0, leftRemove, rightRemove);
        return ans;
    }
};