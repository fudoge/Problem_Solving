#include <bits/stdc++.h>

using namespace std;

int a, b;
vector<bool> isPrime;

bool isUnderprime(int x) {
  if (isPrime[x])
    return false;
  int cnt = 0;
  for (int i = 2; i <= x; ++i) {
    if (!isPrime[i])
      continue;
    while (x % i == 0) {
      x /= i;
      cnt++;
    }
  }

  return isPrime[cnt];
}

int main(int argc, char *argv[]) {
  cin >> a >> b;
  isPrime.resize(100001, true);
  isPrime[0] = false;
  isPrime[1] = false;
  for (int i = 2; i <= 100000; ++i) {
    if (!isPrime[i])
      continue;
    int j = i * 2;
    while (j <= 100000) {
      isPrime[j] = false;
      j += i;
    }
  }

  int ans = 0;
  for (int i = a; i <= b; ++i) {
    if (isUnderprime(i))
      ans++;
  }

  cout << ans << "\n";

  return 0;
}