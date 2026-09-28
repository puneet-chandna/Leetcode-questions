class Solution {
public:
    int maxDepth(string s) {
        int depth=0;
        int cur=0;
        for (int i=0; i< s.length();i++){
            if(s[i] == '(') cur ++;
            else if ( s[i]== ')') cur --;
            depth = max(depth, cur);
        }
        return depth;
    }
};