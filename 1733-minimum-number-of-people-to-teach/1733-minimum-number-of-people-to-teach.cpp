class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
            int m = languages.size();
        vector<unordered_set<int>> knows(m);
        for (int i = 0; i < m; i++)
            knows[i] = unordered_set<int>(languages[i].begin(), languages[i].end());

        unordered_set<int> problemUsers;
        for (auto &f : friendships) {
            int u = f[0] - 1, v = f[1] - 1;
            bool comm = false;
            for (int lang : knows[u])
                if (knows[v].count(lang)) {
                    comm = true;
                    break;
                }
            if (!comm) {
                problemUsers.insert(u);
                problemUsers.insert(v);
            }
        }

        vector<int> countLang(n + 1);
        for (int user : problemUsers)
            for (int lang : knows[user])
                countLang[lang]++;

        int maxKnown = 0;
        for (int lang = 1; lang <= n; lang++)
            maxKnown = max(maxKnown, countLang[lang]);

        return problemUsers.size() - maxKnown;
    }
};