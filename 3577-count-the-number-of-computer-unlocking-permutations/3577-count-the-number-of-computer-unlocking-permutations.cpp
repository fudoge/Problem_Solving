using ll = long long;

const int MOD = 1e9 + 7;

ll fact[100001];
bool built = false;
void build() {
    if (built) return;
    built = true;
    fact[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        fact[i] = fact[i-1] * i % MOD;
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