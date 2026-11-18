#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
    int minChanges(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i+=2) {
            if(s[i] != s[i+1]) ans++;
        }

        return ans;
    }
};