class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        while (word.length() < k) {
            string next_part = "";
            for (char c : word) {
                next_part += (c == 'z' ? 'a' : c + 1);
            }
            word += next_part;
        }
        return word[k - 1];
    }
};