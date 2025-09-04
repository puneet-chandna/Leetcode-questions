class Solution {
public:
    int findClosest(int x, int y, int z) {
        int dist1 = abs(x - z);
        int dist2 = abs(y - z);
        if (dist1 == dist2) return 0;
        return dist1 < dist2 ? 1 : 2;
    }
};