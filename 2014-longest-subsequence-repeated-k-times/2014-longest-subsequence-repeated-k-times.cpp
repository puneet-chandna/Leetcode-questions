class Solution {
public:
    bool check(const string& seq, const string& s, int k) {
        int s_ptr = 0;
        for (int rep = 0; rep < k; ++rep) {
            for (char c : seq) {
                size_t found_pos = string::npos;
                for (int i = s_ptr; i < s.length(); ++i) {
                    if (s[i] == c) {
                        found_pos = i;
                        break;
                    }
                }
                if (found_pos == string::npos) {
                    return false;
                }
                s_ptr = found_pos + 1;
            }
        }
        return true;
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        string result = "";
        vector<int> counts(26, 0);
        for (char c : s) {
            counts[c - 'a']++;
        }

        int max_possible_seq_len = s.length() / k;

        queue<string> q;
        q.push("");

        while (!q.empty()) {
            string current_prefix = q.front();
            q.pop();

            for (char ch = 'z'; ch >= 'a'; --ch) {
                if (counts[ch - 'a'] < k) {
                    continue;
                }

                string next_seq = current_prefix + ch;

                if (next_seq.length() > max_possible_seq_len) {
                    continue;
                }

                if (check(next_seq, s, k)) {
                    if (next_seq.length() > result.length() ||
                        (next_seq.length() == result.length() && next_seq > result)) {
                        result = next_seq;
                    }
                    q.push(next_seq);
                }
            }
        }
        return result;
    }
};