class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int rem = n % 7;
        int firstWeek = 28;
        int lastFullWeek = firstWeek + (weeks - 1) * 7;
        int totalFullWeeks = weeks * (firstWeek + lastFullWeek) / 2;
        int startDay = weeks + 1;
        int totalReamining = (startDay + (startDay + rem - 1)) * rem / 2;
        return totalFullWeeks + totalReamining;
    }
};