#include <bits/stdc++.h>
#include <ostream>

using namespace std;

bool isFit(const string &a, const string &b, int o) {
  int n = a.size();
  int m = b.size();
  for (int i = 0; i < m; ++i) {
    if (o + i < 0)
      continue;
    if (o + i >= n)
      continue;
    if (a[o + i] == '2' && b[i] == '2')
      return false;
  }
  return true;
}

int minMatchSize(string a, string b) {
  int n = a.size();
  int m = b.size();
  int res = a.size() + b.size();
  int start = b.size() * -1 + 1;
  int end = a.size();
  for (int o = start, i = 1; o < end; ++o, ++i) {
    if (isFit(a, b, o)) {
      int len = max(n, o + m) - min(0, o);
      res = min(res, len);
    }
  }
  return res;
}

int main(int argc, char *argv[]) {
  int n, m;
  string s1, s2;

  cin >> s1 >> s2;

  n = s1.size();
  m = s2.size();

  int res1 = minMatchSize(s1, s2);
  int res2 = minMatchSize(s2, s1);

  cout << min(res1, res2) << "\n";

  return 0;
}