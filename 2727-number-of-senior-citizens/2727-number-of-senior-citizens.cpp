#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(const auto &detail : details) {
            if((detail[11] - '0') * 10 + (detail[12] - '0') > 60) ans++;
        }

        return ans;
    }
};