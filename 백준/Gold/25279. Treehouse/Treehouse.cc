#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;

struct PairHash {
  size_t operator()(const pii &p) const {
    return hash<int>()((ll)p.first) ^ (hash<int>()((ll)p.second) << 32);
  }
};

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<pii> points(n);
  unordered_set<pii, PairHash> pointSet;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    points[i] = {a, b};
    pointSet.insert(points[i]);
  }

  int ans = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int x1 = points[i].first, y1 = points[i].second;
      int x2 = points[j].first, y2 = points[j].second;
      int dx = x2 - x1;
      int dy = y2 - y1;

      pii p3 = {x1 - dy, y1 + dx};
      pii p4 = {x2 - dy, y2 + dx};
      if (pointSet.find(p3) != pointSet.end() &&
          pointSet.find(p4) != pointSet.end()) {
        ans++;
      }

      p3 = {x1 + dy, y1 - dx};
      p4 = {x2 + dy, y2 - dx};

      if (pointSet.find(p3) != pointSet.end() &&
          pointSet.find(p4) != pointSet.end()) {
        ans++;
      }
    }
  }

  cout << ans / 4 << "\n";
  return 0;
}