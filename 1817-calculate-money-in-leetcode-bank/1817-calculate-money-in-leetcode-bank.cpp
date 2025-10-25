class Solution {
   public:
    int totalMoney(int n) {
        int ans = 0;
        int cycle = 0;
        int day = 0;
        for (int i = 0; i < n; i++) {
            ans += cycle + (day + 1);
            day++;
            if (day == 7) {
                day = 0;
                cycle++;
            }
        }

        return ans;
    }
};