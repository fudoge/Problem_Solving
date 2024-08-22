#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    int findComplement(int num) {
        return num ^ (ulong(1 << ulong(log2(num)) + 1) -1);
    }
};