#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n), d(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }

  vector<ll> ab, cd;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ab.emplace_back(a[i] + b[j]);
      cd.emplace_back(c[i] + d[j]);
    }
  }

  ll ans = 0;

  int m = ab.size();
  sort(ab.begin(), ab.end());
  sort(cd.begin(), cd.end());

  for (int i = 0; i < m; ++i) {
    ll target = -ab[i];
    int l = lower_bound(cd.begin(), cd.end(), target) - cd.begin();
    int r = upper_bound(cd.begin(), cd.end(), target) - cd.begin();

    ans += r - l;
  }

  cout << ans << "\n";

  return 0;
}