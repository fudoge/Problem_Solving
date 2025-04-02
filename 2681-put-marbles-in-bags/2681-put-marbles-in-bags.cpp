using ll = long long;
using pii = pair<int, int>;
class Solution {
   public:
    ll putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<ll> pairsums;
        for (int i = 0; i < n - 1; i++) {
            pairsums.emplace_back(weights[i] + weights[i + 1]);
        }
        sort(pairsums.begin(), pairsums.end());

        ll maxSum = 0, minSum = 0;
        for (int i = 0; i < k - 1; i++) {
            minSum += pairsums[i];
            maxSum += pairsums[n - 2 - i];
        }

        return maxSum - minSum;
    }
};