#include <bits/stdc++.h>
#define ll long long
#define MOD (int)(1e9 + 7)

using namespace std;

ll m;
ll n, s;

ll solve(ll b) {
  ll res = 1;
  ll exp = MOD - 2;
  b %= MOD;
  while (exp > 0) {
    if (exp % 2 == 1)
      res = (res * b) % MOD;
    b = (b * b) % MOD;
    exp /= 2;
  }
  return res;
}

int main(int argc, char *argv[]) {
  ll ans = 0;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> n >> s;
    ans = (ans + s * solve(n)) % MOD;
  }
  cout << ans << "\n";
  return 0;
}