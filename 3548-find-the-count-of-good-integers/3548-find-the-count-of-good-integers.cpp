#pragma GCC optimize("O3", "unroll-loops");
static const int __ = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

using ll = long long;

class Solution {
    int fact[11];

   public:
    void initFactorial() {
        fact[0] = 1;
        for (int i = 1; i <= 10; i++) {
            fact[i] = fact[i - 1] * i;
        }
    }
    void generate(int l, vector<int> &arr, vector<vector<int>> &res) {
        if (arr.size() == l) {
            vector<int> cpy(arr.begin(), arr.end());
            res.emplace_back(cpy);
            return;
        }
        for (int i = 0; i <= 9; i++) {
            arr.emplace_back(i);
            generate(l, arr, res);
            arr.pop_back();
        }
    }

    vector<vector<int>> getPalindromes(int n) {
        int l = n / 2 + n % 2;
        vector<vector<int>> res;
        vector<int> temp;
        for (int i = 1; i <= 9; i++) {
            temp.emplace_back(i);
            generate(l, temp, res);
            temp.pop_back();
        }
        return res;
    }

    vector<ll> getKPalindromes(int n, int k, vector<vector<int>> &palindromes) {
        unordered_set<ll> unique;

        for (const auto &half : palindromes) {
            int l = n / 2 + n % 2;
            if (half.size() != (unsigned)l) continue;
            ll full = 0;
            for (int i = 0; i < half.size(); i++) {
                full = full * 10 + half[i];
            }
            int start = (n % 2 == 1) ? (half.size() - 2) : (half.size() - 1);
            for (int i = start; i >= 0; i--) {
                full = full * 10 + half[i];
            }
            if (full % k == 0) {
                if (unique.find(full) == unique.end()) {
                    unique.insert(full);
                }
            }
        }
        vector<ll> res(unique.begin(), unique.end());
        return res;
    }

    ll getCount(int n, ll pat) {
        ll total = fact[n];

        for (int i = 0; i < 10; i++) {
            int f = (pat >> (i * 4)) & 15;
            total /= fact[f];
        }

        // Leading zero 제거
        ll invalid = 0;
        int zeroCount = (pat >> 0) & 15;
        if (zeroCount > 0) {
            ll temp = fact[n - 1];
            for (int i = 0; i < 10; i++) {
                int f = (pat >> (i * 4)) & 15;
                if (i == 0) f--;
                temp /= fact[f];
            }
            invalid = temp;
        }

        return total - invalid;
    }

    long long countGoodIntegers(int n, int k) {
        if (n == 1) {
            ll ans = 0;
            for (int i = 1; i <= 9; i++) {
                if (i % k == 0) ans++;
            }
            return ans;
        }
        initFactorial();
        vector<vector<int>> palindromes = getPalindromes(n);
        vector<ll> kPalindromes = getKPalindromes(n, k, palindromes);

        unordered_set<ll> patterns;
        for (ll kpal : kPalindromes) {
            vector<int> freq(10, 0);
            ll patternId = 0;
            ll x = kpal;
            while (x > 0) {
                freq[x % 10]++;
                x /= 10;
            }
            for (int i = 0; i < 10; i++) {
                patternId |= (1LL * freq[i] << (i * 4));
            }
            patterns.insert(patternId);
        }

        ll ans = 0;
        for (ll pat : patterns) {
            ans += getCount(n, pat);
        }
        return ans;
    }
};