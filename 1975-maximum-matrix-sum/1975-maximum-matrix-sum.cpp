#pragma GCC optimize("O3", "unroll-loops");
static const int __ = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
using ll = long long;
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int maximumNeg = INT_MAX;
        ll ans = 0;
        int cnt = 0;
        bool existZero = false;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] < 0) {
                    cnt++;
                }
                maximumNeg = min(maximumNeg, abs(matrix[i][j]));
                ans += abs(matrix[i][j]);
            }
        }

        if(cnt % 2 && !existZero) ans -= 2 * maximumNeg;
        return ans;
    }
};