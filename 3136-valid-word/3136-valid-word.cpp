class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) return false;
    bool hasV = false, hasC = false;
    for (char c : word) {
        if (isdigit(c)) continue;
        if (isalpha(c)) {
            char x = tolower(c);
            if (x=='a'||x=='e'||x=='i'||x=='o'||x=='u') hasV = true;
            else hasC = true;
        } else return false;
    }
    return hasV && hasC;
    }
};