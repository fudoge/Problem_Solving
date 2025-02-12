#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;

struct PairHash {
  size_t operator()(const pii &p) const {
    return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
  }
};

ll euclidian_dist(pii &a, pii &b) {
  ll xdist = b.first - a.first;
  ll ydist = b.second - a.second;
  return xdist * xdist + ydist * ydist;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<pii> points(n);
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    points[i] = {a, b};
  }

  unordered_map<ll, unordered_set<pii, PairHash>>
      dist_to_coordiante_ids; // distToCoordianteIDs[dist^2] = {i, j} if
                              // points[i] points[j]

  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      ll dist = euclidian_dist(points[i], points[j]);
      dist_to_coordiante_ids[dist].insert({i, j});
    }
  }

  int ans = 0;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      ll side = euclidian_dist(points[i], points[j]);
      for (const auto &p : dist_to_coordiante_ids[side]) {
        if (p.first <= i && p.second <= j)
          continue;
        ll ipf = euclidian_dist(points[i], points[p.first]);
        ll ips = euclidian_dist(points[i], points[p.second]);
        ll jpf = euclidian_dist(points[j], points[p.first]);
        ll jps = euclidian_dist(points[j], points[p.second]);

        if (ipf == side && jps == side && ips == side * 2 && jpf == side * 2)
          ans++;
        else if (ips == side && jpf == side && ipf == side * 2 &&
                 jps == side * 2)
          ans++;
      }
    }
  }

  cout << ans / 2 << "\n";

  return 0;
}