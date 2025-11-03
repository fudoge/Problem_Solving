#pragma GCC optimize("O3", "unroll-loops");
static const int __ = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
   public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int ans = 0;
        for (int i = 0; i < n;) {
            int j = i + 1;
            int sum = neededTime[i];
            int maximum = neededTime[i];
            while (j < n && colors[i] == colors[j]) {
                sum += neededTime[j];
                maximum = max(maximum, neededTime[j]);
                j++;
            }

            ans += (sum - maximum);
            i = j;
        }

        return ans;
    }
};