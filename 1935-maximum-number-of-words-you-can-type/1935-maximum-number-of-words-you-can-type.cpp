class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
       vector<bool> broken(26, false);
        for (char c : brokenLetters)
            broken[c - 'a'] = true;
        int result = 0;
        string word;
        for (size_t i = 0; i <= text.size(); ++i) {
            if (i == text.size() || text[i] == ' ') {
                // End of word
                if (!word.empty()) {
                    bool ok = true;
                    for (char wc : word) {
                        if (broken[wc - 'a']) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) result++;
                    word.clear();
                }
            } else {
                word.push_back(text[i]);
            }
        }
        return result; 
    }
};