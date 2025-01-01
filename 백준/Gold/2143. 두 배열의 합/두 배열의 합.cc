#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, n, m;
  int a[1001], b[1001];
  vector<ll> sumA;
  vector<ll> sumB;
  cin >> t;
  cin >> n >> a[0];
  for (int i = 1; i < n; ++i) {
    cin >> a[i];
    a[i] += a[i - 1];
  }
  cin >> m >> b[0];
  for (int i = 1; i < m; ++i) {
    cin >> b[i];
    b[i] += b[i - 1];
  }

  for (int i = 0; i < n; ++i) {
    sumA.emplace_back(a[i]);
    for (int j = 0; j < i; ++j) {
      sumA.emplace_back(a[i] - a[j]);
    }
  }
  for (int i = 0; i < m; ++i) {
    sumB.emplace_back(b[i]);
    for (int j = 0; j < i; ++j) {
      sumB.emplace_back(b[i] - b[j]);
    }
  }

  sort(sumB.begin(), sumB.end());

  ll ans = 0;
  for (int i = 0; i < sumA.size(); ++i) {
    int target = t - sumA[i];
    int ub = upper_bound(sumB.begin(), sumB.end(), target) - sumB.begin();
    int lb = lower_bound(sumB.begin(), sumB.end(), target) - sumB.begin();
    ans += ub - lb;
  }

  cout << ans << "\n";

  return 0;
}