#include <bits/stdc++.h>

using namespace std;

int n;

bool isPrime(int x) {
  if (x == 2 || x == 3)
    return true;
  int r = sqrt(x);
  for (int i = 2; i <= r; ++i) {
    if (x % i == 0)
      return false;
  }
  return true;
}

int main(int argc, char *argv[]) {
  cin >> n;

  vector<bool> sieve(n + 1, true);
  vector<int> primes;
  sieve[0] = false;
  sieve[1] = false;
  for (int i = 2; i <= n; ++i) {
    if (!sieve[i])
      continue;
    if (isPrime(i)) {
      primes.push_back(i);
      for (int j = i; j <= n; j += i) {
        sieve[j] = false;
      }
    }
  }

  int left = 0;
  int m = primes.size();
  int sum = 0;
  int ans = 0;
  for (int right = 0; right < m; ++right) {
    sum += primes[right];
    while (left <= right && sum >= n) {
      if (sum == n)
        ans++;
      sum -= primes[left];
      left++;
    }
  }

  cout << ans << "\n";

  return 0;
}