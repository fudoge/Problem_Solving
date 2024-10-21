#pragma GCC optimize("03", "unrol-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
private:
    int ans;
    int n;
    unordered_map<string, int> exists;
    void solve(int idx, int count, string &s) {
        if(idx >= n) {
            ans = max(ans, count);
            return;
        }

        string temp = string(1, s[idx]);
        for(int i = idx+1; i <= n; ++i) {
            if(exists[temp] == 0) {
                exists[temp]++;
                solve(i, count+1, s);
                exists[temp]--;
            }
            temp += s[i];
        }
    }
public:
    int maxUniqueSplit(string s) {
        n = s.size();
        solve(0, 0, s);
        return ans;
    }
};