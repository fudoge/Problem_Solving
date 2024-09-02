#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long total = 0;
        for(const auto &x : chalk) {
            total += x;
        }
        k %= total;

        for(int i = 0; i < chalk.size(); i++) {
            if(chalk[i] <= k) k -= chalk[i];
            else return i;
        }

        return 0;
    }
};