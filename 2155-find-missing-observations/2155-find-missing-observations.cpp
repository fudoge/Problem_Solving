#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = 0;
        int m = rolls.size();
        for(int roll : rolls) {
            sum += roll;
        }

        int goal = (m + n) * mean;
        int left = goal - sum;

        if(left > 6 * n || left < n) return {};

        vector<int> ans (n, left / n);
        left %= n;

        for(int i = 0; left > 0; i++) {
            ans[i]++;
            left--;
        }

        return ans;
    }
};