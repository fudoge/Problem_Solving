#pragma GCC optimize("O3", "unroll-loops");
static const int __ = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
using ll = long long;
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        ll ans = 0;

        for(int i = 0; i < n;) {
            int j = i+1;
            while(j < n && prices[j] == prices[j-1]-1) {
                ans += j-i;
                j++;
            }
            ans += j-i;
            i = j;
        }

        return ans;
    }
};