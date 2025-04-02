#pragma GCC optimize("O3", "unroll-loops");
using ll = long long;
using pii = pair<int, int>;
const int MOD = 1e9 + 7;
vector<int> primes;
vector<bool> is_prime;
static const auto init = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    is_prime.resize(100001, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i <= 100000; i++) {
        if (!is_prime[i]) continue;
        primes.emplace_back(i);
        for (int j = 2 * i; j <= 100000; j += i) {
            is_prime[j] = false;
        }
    }
    return 0;
}();

struct comp {
    bool operator()(const pii &a, const pii &b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};

class Solution {
   public:
    ll powmod(ll base, ll exp) {
        ll res = 1;
        while (exp > 0) {
            if (exp % 2) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    int get_prime_score(int x) {
        int cnt = 0;
        for (int p : primes) {
            if (1LL * p * p > x) break;
            if (x % p == 0) {
                cnt++;
                while (x % p == 0) x /= p;
            }
        }
        if (x > 1) cnt++;
        return cnt;
    }

    int maximumScore(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> primescores(n, 0);
        ll ans = 1;

        for (int i = 0; i < n; i++) {
            primescores[i] = get_prime_score(nums[i]);
        }

        vector<int> left(n), right(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && primescores[st.top()] < primescores[i])
                st.pop();
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && primescores[st.top()] <= primescores[i])
                st.pop();
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        vector<pii> candidates(n);
        for (int i = 0; i < n; i++) {
            candidates[i] = {nums[i], i};
        }
        sort(candidates.begin(), candidates.end(), comp());

        for (const auto &[num, idx] : candidates) {
            ll use = 1LL * (idx - left[idx]) * (right[idx] - idx);
            use = min(use, (ll)k);
            ans = (ans * powmod(num, use)) % MOD;
            k -= use;
            if (k == 0) break;
        }

        return ans % MOD;
    }
};