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