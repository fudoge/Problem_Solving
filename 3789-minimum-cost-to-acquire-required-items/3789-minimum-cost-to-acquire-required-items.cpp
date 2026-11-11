// started_at: 09:40
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = 0;
        if(costBoth <= cost1 + cost2) {
            int le = min(need1, need2);
            ans += 1LL * le * costBoth;
            need1 -= le;
            need2 -= le;
        }

        if(need1 != 0) {
            int cost = costBoth < cost1? costBoth : cost1;
            ans += 1LL * need1 * cost;
            need1 = 0;
        }

        if(need2 != 0) {
            int cost = costBoth < cost2? costBoth : cost2;
            ans += 1LL * need2 * cost;
            need2 = 0;
        }

        return ans;
    }
};