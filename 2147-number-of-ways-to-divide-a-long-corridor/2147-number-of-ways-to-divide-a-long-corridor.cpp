#pragma GCC optimize("O3", "unroll-loops");
static const int __ = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
using ll = long long;
class Solution {
public:
    int numberOfWays(string corridor) {
        int n = corridor.size();
        int MOD = 1e9 + 7;
        
        int cnt = 0;
        int streak = 0;
        ll ans = 1; 
        int len = 0;
        for(int i = 0; i < n; i++) {
            if(corridor[i] == 'S') {
                streak++;
                cnt++;
                if(streak >= 2) {
                    int j = i+1;
                    while(j < n && corridor[j] == 'P') {
                        j++;
                    }
                    if(j < n) ans = (ans * (j-i)) % MOD;
                    streak = 0;
                    i = j-1;
                }
            }
        }

        if(cnt%2 || cnt == 0) return 0;
        return ans;
    }
};