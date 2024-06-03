static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    int scoreOfString(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n-1; i++) {
            ans += abs(s[i] - s[i+1]);
        }

        return ans;
    }
};