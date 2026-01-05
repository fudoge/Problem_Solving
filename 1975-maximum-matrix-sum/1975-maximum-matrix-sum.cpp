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
                } else if(matrix[i][j] == 0) {
                    existZero = true;
                }
                maximumNeg = min(maximumNeg, abs(matrix[i][j]));
                ans += abs(matrix[i][j]);
            }
        }

        if(cnt % 2 && !existZero) ans -= 2 * maximumNeg;
        return ans;
    }
};