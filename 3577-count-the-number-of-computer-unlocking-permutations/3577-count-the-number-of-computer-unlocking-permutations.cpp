using ll = long long;

const int MOD = 1e9 + 7;

ll fact[100001], invfact[100001];
bool built = false;

ll bpow(ll base, ll exp) {
    ll res = 1;
    while(exp) {
        if(exp&1) res = (res * base) % MOD;
        exp >>= 1;
        base = (base * base) % MOD;
    }
    return res;
}

void build() {
    if (built) return;
    built = true;
    fact[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        fact[i] = fact[i-1] * i % MOD;
    }
    invfact[100000] = bpow(fact[100000], MOD-2);
    for (int i = 99999; i >= 0; i--) {
        invfact[i] = invfact[i+1] * (i+1) % MOD;
    }
}


class Solution {
    int MOD = 1e9 + 7;
public:
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        if(*min_element(complexity.begin()+1, complexity.end()) <= complexity[0]) {
            return 0;
        }
        build();
        return fact[n-1];
    }
};