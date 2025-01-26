#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int ccw(pll &a, pll &b, pll &c) {
  ll res = (b.first - a.first) * (c.second - a.second) -
           (b.second - a.second) * (c.first - a.first);
  if (res > 0)
    return 1;
  if (res < 0)
    return -1;
  return 0;
}

bool isPoint(pll &p1, pll &p2, pll &p) {
  return min(p1.first, p2.first) <= p.first &&
         p.first <= max(p1.first, p2.first) &&
         min(p1.second, p2.second) <= p.second &&
         p.second <= max(p1.second, p2.second);
}

bool isIntersect(pll &a, pll &b, pll &c, pll &d) {
  int ccw1 = ccw(a, b, c);
  int ccw2 = ccw(a, b, d);
  int ccw3 = ccw(c, d, a);
  int ccw4 = ccw(c, d, b);

  if (ccw1 * ccw2 < 0 && ccw3 * ccw4 < 0)
    return true;

  if (ccw1 == 0 && isPoint(a, b, c))
    return true;
  if (ccw2 == 0 && isPoint(a, b, d))
    return true;
  if (ccw3 == 0 && isPoint(c, d, a))
    return true;
  if (ccw4 == 0 && isPoint(c, d, b))
    return true;
  return false;
}

int main() {
  pll a, b, c, d;
  cin >> a.first >> a.second >> b.first >> b.second;
  cin >> c.first >> c.second >> d.first >> d.second;

  cout << (isIntersect(a, b, c, d) ? 1 : 0) << "\n";

  return 0;
}