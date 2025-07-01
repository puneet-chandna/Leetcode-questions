class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        vector<pair<char, int>> groups;
        int i = 0;
        while (i < n) {
            char c = word[i];
            int j = i;
            while (j < n && word[j] == c) j++;
            groups.push_back({c, j - i});
            i = j;
        }
        int total = 1;
        for (auto [c, count] : groups)
            total += count - 1;
        return total;
    }
};