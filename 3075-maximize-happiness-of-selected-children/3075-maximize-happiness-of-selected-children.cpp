#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
using ll = long long;
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<>());
        ll ans = 0;
        for(int i = 0; i < k; i++) {
            ans += max(0, happiness[i] - i);
        }

        return ans;
    }
};