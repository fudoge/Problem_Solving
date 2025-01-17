#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(ll x, vector<ll> &pows) {
  ll res = x & 1;
  for (int i = 55; i > 0; --i) {
    if (x & ((ll)1 << i)) {
      res += pows[i - 1];
      res += (x - ((ll)1 << i) + 1);
      x &= ~((ll)1 << i);
    }
  }
  return res;
}

int main(int argc, char *argv[]) {
  ll a, b;
  cin >> a >> b;
  vector<ll> pows(55);
  pows[0] = 1;
  for (int i = 1; i < 55; ++i) {
    pows[i] = pows[i - 1] * 2 + ((ll)1 << i);
  }

  cout << solve(b, pows) - solve(a - 1, pows) << "\n";

  return 0;
}