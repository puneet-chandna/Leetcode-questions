class Solution {
public:
    string clearStars(string s) {
        stack<int> charStacks[26];
        int n = s.length();
        vector<bool> toRemove(n, false);

        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                toRemove[i] = true;
                for (int j = 0; j < 26; ++j) {
                    if (!charStacks[j].empty()) {
                        toRemove[charStacks[j].top()] = true;
                        charStacks[j].pop();
                        break;
                    }
                }
            } else {
                charStacks[s[i] - 'a'].push(i);
            }
        }

        string result;
        for (int i = 0; i < n; ++i) {
            if (!toRemove[i]) {
                result += s[i];
            }
        }

        return result;
    }
};