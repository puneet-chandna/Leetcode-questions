class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiagSq = 0, maxArea = 0;
        for (auto& d : dimensions) {
            int l = d[0], w = d[1];
            int diagSq = l * l + w * w;
            int area = l * w;
            if (diagSq > maxDiagSq || (diagSq == maxDiagSq && area > maxArea)) {
                maxDiagSq = diagSq;
                maxArea = area;
            }
        }
        return maxArea;
    }
};