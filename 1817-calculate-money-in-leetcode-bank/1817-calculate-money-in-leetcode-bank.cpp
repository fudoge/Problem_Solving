class Solution {
public:
    int totalMoney(int n) {
        int sum = 0;
        int week = 1;
        int weekday = 0;
        for(int i = 0; i < n; i++, weekday++) {
            if(weekday >= 7) {
                week++;
                weekday %=7;
            }
            sum += week + weekday;
        }

        return sum;
    }
};