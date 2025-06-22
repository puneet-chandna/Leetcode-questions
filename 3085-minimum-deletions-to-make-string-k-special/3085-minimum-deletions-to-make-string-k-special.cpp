class Solution {
public:
    int minimumDeletions(string word, int k) {
        std::map<char, int> freq_map;
        for (char c : word) {
            freq_map[c]++;
        }

        std::vector<int> freqs;
        for (auto const& [key, val] : freq_map) {
            freqs.push_back(val);
        }

        int min_overall_deletions = std::numeric_limits<int>::max();
        if (freqs.empty()) {
            return 0;
        }
        
        std::vector<int> unique_freqs = freqs;
        std::sort(unique_freqs.begin(), unique_freqs.end());
        unique_freqs.erase(std::unique(unique_freqs.begin(), unique_freqs.end()), unique_freqs.end());
        
        if (unique_freqs.empty() || unique_freqs[0] != 0) {
            unique_freqs.insert(unique_freqs.begin(), 0);
        }


        for (int min_f : unique_freqs) {
            int current_deletions = 0;
            for (int f : freqs) {
                if (f < min_f) {
                    current_deletions += f;
                } else if (f > min_f + k) {
                    current_deletions += (f - (min_f + k));
                }
            }
            min_overall_deletions = std::min(min_overall_deletions, current_deletions);
        }

        return min_overall_deletions;
    }
};