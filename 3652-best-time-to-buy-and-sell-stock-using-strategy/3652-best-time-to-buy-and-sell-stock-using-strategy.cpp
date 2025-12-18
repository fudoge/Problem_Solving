using ll = long long;
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size(); 
        int k2 = k/2;
        vector<ll> pref(n+1, 0);

        for(int i = 0; i < n; i++) {
            pref[i+1] = pref[i] + 1LL * strategy[i] * prices[i];
        } 

        ll modify = reduce(prices.begin()+k2, prices.begin()+k, 0LL);
        ll ans = max(pref[n], modify+pref[n]-pref[k]);

        for(int i = 1; i+k <= n; i++) {
            modify += prices[i+k-1]-prices[i+k2-1];
            ans = max(ans, modify+pref[n]-pref[i+k]+pref[i]);
        }

        return ans;
    }
};