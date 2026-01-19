#pragma GCC optimize("O3", "unroll-loops");
static const int __ = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    int check(vector<vector<int>>& pref, int len, int threshold) {
        for(int i = len; i < pref.size(); i++) {
            for(int j = len; j < pref[0].size(); j++) {
                int sum = pref[i][j] - pref[i-len][j] - pref[i][j-len] + pref[i-len][j-len];
                if(sum <= threshold) return true;
            }
        }

        return false;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> pref(m+1, vector<int>(n+1));

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                pref[i][j] = mat[i-1][j-1] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
            }
        }
        int ans = 0;
        int lo = 0;
        int hi = min(n, m);
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            if(check(pref, mid, threshold)) {
                ans = mid; 
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }
        return ans;
    }
};