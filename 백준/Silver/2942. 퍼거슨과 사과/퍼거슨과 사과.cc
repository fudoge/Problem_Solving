#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int R, G;
  cin >> R >> G;

  int commonDivisor = gcd(max(R, G), min(R, G));

  for (int i = 1; i <= commonDivisor; ++i) {
    if (R % i == 0 && G % i == 0) {
      cout << i << " " << R / i << " " << G / i << "\n";
    }
  }

  return 0;
}