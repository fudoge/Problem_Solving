using ll = long long;
class Solution {
   public:
    const int MOD = 1e9 + 7;
    ll bpow(ll base, ll exp) {
        ll res = 1;
        while (exp > 0) {
            if (exp % 2) {
                res = (res * base) % MOD;
                exp--;
            }
            exp >>= 1;
            base = (base * base) % MOD;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        ll numOdd = n / 2;
        ll numEven = n / 2 + (n % 2);

        return (bpow(5, numEven) * bpow(4, numOdd)) % MOD;
    }
};