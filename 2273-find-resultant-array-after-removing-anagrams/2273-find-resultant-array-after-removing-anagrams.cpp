class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;
        string prev = "";
        
        for (auto &word : words) {
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());
            
            if (sortedWord != prev) {  
                res.push_back(word);
                prev = sortedWord;
            }
        }
        return res;
    }
};