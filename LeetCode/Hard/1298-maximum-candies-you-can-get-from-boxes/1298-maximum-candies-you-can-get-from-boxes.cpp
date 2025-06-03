class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        
        vector<bool> haveBox(n, false);
        
        vector<bool> haveKey(n, false);

        vector<bool> used(n, false);
        
        queue<int> q;
        
        for (int b : initialBoxes) {
            haveBox[b] = true;
            if (status[b] == 1) {
                q.push(b);
                used[b] = true;
            }
        }
        
        int totalCandies = 0;
        
        while (!q.empty()) {
            int box = q.front();
            q.pop();
            
            totalCandies += candies[box];
            
            for (int k : keys[box]) {
                if (!haveKey[k]) {
                    haveKey[k] = true;
                    if (haveBox[k] && !used[k] && status[k] == 0) {
                        q.push(k);
                        used[k] = true;
                    }
                }
            }
            
            for (int newBox : containedBoxes[box]) {
                if (!haveBox[newBox]) {
                    haveBox[newBox] = true;
                    
                    if (!used[newBox] && (status[newBox] == 1 || haveKey[newBox])) {
                        q.push(newBox);
                        used[newBox] = true;
                    }
                }
            }
        }
        
        return totalCandies;
    }
};