#pragma GCC optimize("O3", "unroll-loops");
static const int __ = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
   public:
    int smallestRepunitDivByK(int k) {
        if (k == 1) return 1;
        if (k % 2 == 0 || k % 5 == 0) return -1;
        vector<int> firstModK(k, -1);
        int num = 1;
        int curr = 1;

        while (true) {
            if (firstModK[num] != -1) break;
            firstModK[num] = curr;
            num = ((num * 10) + 1) % k;
            curr++;
        }

        return firstModK[0];
    }
};