#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

ll lcm(ll a, ll b, ll c) {
  return a*b*c/gcd(a, b*c/gcd(b,c));
}

ll solution(int n) {
  ll res = max(lcm(n, n-1, n-2), max(lcm(n, n-1, n-3), lcm(n-1, n-2, n-3)));

  return res;
}

int main (int argc, char *argv[]) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0); int t, n;
  cin >> t;

  for(int i = 0; i < t; ++i) {
    cin >> n;
    ll l = solution(n);
    cout << l << "\n";
  }

  return 0;
}