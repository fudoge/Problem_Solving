using ll = long long;

class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;

        ll A = 6; // Type 1(A B A)
        ll B = 6; // Type 2(A B C)

        for (int i = 2; i <= n; i++) {
            ll newA = (3 * A + 2 * B) % MOD; // 3*(A B A) and 2*(A B C)
            ll newB = (2 * A + 2 * B) % MOD; // 3*(A B A) and 2*(A B C)
            A = newA;
            B = newB;
        }
        return (A + B) % MOD;
    }
};