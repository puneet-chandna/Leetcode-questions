class Solution {
public:
    int minMaxDifference(int num) {
        std::string s_num = std::to_string(num);
        
        std::string max_s = s_num;
        char char_to_replace_max = '\0';

        for (char c : max_s) {
            if (c != '9') {
                char_to_replace_max = c;
                break;
            }
        }
        
        if (char_to_replace_max != '\0') {
            for (char &c : max_s) {
                if (c == char_to_replace_max) {
                    c = '9';
                }
            }
        }

        std::string min_s = s_num;
        char char_to_replace_min = min_s[0];
        
        for (char &c : min_s) {
            if (c == char_to_replace_min) {
                c = '0';
            }
        }
        
        int max_val = std::stoi(max_s);
        int min_val = std::stoi(min_s);
        
        return max_val - min_val;
    }
};