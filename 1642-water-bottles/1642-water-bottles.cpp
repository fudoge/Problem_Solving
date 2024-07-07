#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        int emptyBottles = 0;
        while(numBottles > 0) {
            ans += numBottles;
            emptyBottles += numBottles % numExchange;
            numBottles /= numExchange;

            numBottles += emptyBottles / numExchange;
            emptyBottles %= numExchange;
        }
        return ans;
    }
};