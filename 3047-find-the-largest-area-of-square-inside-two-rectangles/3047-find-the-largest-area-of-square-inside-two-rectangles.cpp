#pragma GCC optimize("O3", "unroll-loops");
static const int __ = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
using ll = long long;
class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        ll ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int blX = max(bottomLeft[i][0], bottomLeft[j][0]);
                int blY = max(bottomLeft[i][1], bottomLeft[j][1]);

                int trX = min(topRight[i][0], topRight[j][0]);
                int trY = min(topRight[i][1], topRight[j][1]);

                if(blX < trX && blY < trY) {
                    ll side = min(trX - blX, trY - blY);
                    ans = max(ans, side * side);
                }
            }
        } 

        return ans;
    }
};