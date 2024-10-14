#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(ll a, ll b, ll c) {
  if (b == 0)
    return 1 % c;
  if (b == 1)
    return a % c;

  ll half = solve(a, b / 2, c);
  if (b % 2 == 0) {
    return (half * half) % c;
  } else {
    return (((half * half) % c) * a) % c;
  }
}

int main() {
  ll a, b, c;
  cin >> a >> b >> c;

  cout << solve(a, b, c) << "\n";
  return 0;
}