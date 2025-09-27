class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double best = 0.0;
        int n = points.size();
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    long x1 = points[i][0], y1 = points[i][1];
                    long x2 = points[j][0], y2 = points[j][1];
                    long x3 = points[k][0], y3 = points[k][1];
                    long cross = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
                    double area = fabs(cross) / 2.0;
                    best = max(best, area);
                }
            }
        }
        return best;
    }
};