class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
       unordered_set<string> exact;
        unordered_map<string, string> lower_map;
        unordered_map<string, string> vowel_map;

        auto toLower = [&](const string &w) {
            string s = w;
            for (char &c : s) c = tolower(c);
            return s;
        };

        auto maskVowels = [&](const string &w) {
            string s = w;
            for (char &c : s) {
                char lc = tolower(c);
                if (lc == 'a' || lc == 'e' || lc == 'i' || lc == 'o' || lc == 'u')
                    c = '*';
                else
                    c = lc;
            }
            return s;
        };

       
        for (auto &w : wordlist) {
            exact.insert(w);

            string lw = toLower(w);
            if (lower_map.find(lw) == lower_map.end())
                lower_map[lw] = w;

            string vw = maskVowels(w);
            if (vowel_map.find(vw) == vowel_map.end())
                vowel_map[vw] = w;
        }

        vector<string> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            if (exact.find(q) != exact.end()) {
                ans.push_back(q);
            } else {
                string lq = toLower(q);
                if (lower_map.find(lq) != lower_map.end()) {
                    ans.push_back(lower_map[lq]);
                } else {
                    string vq = maskVowels(q);
                    if (vowel_map.find(vq) != vowel_map.end()) {
                        ans.push_back(vowel_map[vq]);
                    } else {
                        ans.push_back("");
                    }
                }
            }
        }

        return ans; 
    }
};