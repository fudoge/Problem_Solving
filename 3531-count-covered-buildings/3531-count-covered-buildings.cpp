#pragma GCC optimize("O3", "unroll-loops");
static const int __ = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> maxX(n+1);
        vector<int> minX(n+1, n+1);
        vector<int> maxY(n+1);
        vector<int> minY(n+1, n+1);

        for(const auto &b : buildings) {
            int x = b[0], y = b[1];
            maxX[x] = max(maxX[x], y);
            minX[x] = min(minX[x], y);
            maxY[y] = max(maxY[y], x);
            minY[y] = min(minY[y], x);
        }

        int ans = 0;
        for(const auto &b : buildings) {
            int x = b[0], y = b[1];
            if(y > minX[x] && y < maxX[x] && x > minY[y] && x < maxY[y]) {
                ans++;
            }
        }

        return ans;
    }
};