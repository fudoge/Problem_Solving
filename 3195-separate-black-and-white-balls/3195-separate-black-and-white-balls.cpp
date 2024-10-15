#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size();
        int ones = 0;
        long long ans = 0;

        for(const auto &ch : s) {
            if(ch == '1') ones++;
            else ans += ones;
        }
        return ans;
    }
};