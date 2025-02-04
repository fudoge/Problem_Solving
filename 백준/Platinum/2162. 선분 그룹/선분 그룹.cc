#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>

using namespace std;

struct Line {
  int x1;
  int y1;
  int x2;
  int y2;
  Line(int x1, int y1, int x2, int y2) {
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
  }
};

int ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
  ll res = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
  if (res > 0)
    return 1;
  if (res < 0)
    return -1;
  return 0;
}

bool isPoint(int x, int y, int x1, int y1, int x2, int y2) {
  return x >= min(x1, x2) && x <= max(x1, x2) && y >= min(y1, y2) &&
         y <= max(y1, y2);
}

bool isIntersect(int i, int j, vector<Line *> &lines) {
  int ccw1 = ccw(lines[i]->x1, lines[i]->y1, lines[i]->x2, lines[i]->y2,
                 lines[j]->x1, lines[j]->y1);
  int ccw2 = ccw(lines[i]->x1, lines[i]->y1, lines[i]->x2, lines[i]->y2,
                 lines[j]->x2, lines[j]->y2);
  int ccw3 = ccw(lines[j]->x1, lines[j]->y1, lines[j]->x2, lines[j]->y2,
                 lines[i]->x1, lines[i]->y1);
  int ccw4 = ccw(lines[j]->x1, lines[j]->y1, lines[j]->x2, lines[j]->y2,
                 lines[i]->x2, lines[i]->y2);

  if (ccw1 * ccw2 < 0 && ccw3 * ccw4 < 0)
    return true;

  if (ccw1 == 0 && isPoint(lines[j]->x1, lines[j]->y1, lines[i]->x1,
                           lines[i]->y1, lines[i]->x2, lines[i]->y2))
    return true;
  if (ccw2 == 0 && isPoint(lines[j]->x2, lines[j]->y2, lines[i]->x1,
                           lines[i]->y1, lines[i]->x2, lines[i]->y2))
    return true;
  if (ccw3 == 0 && isPoint(lines[i]->x1, lines[i]->y1, lines[j]->x1,
                           lines[j]->y1, lines[j]->x2, lines[j]->y2))
    return true;
  if (ccw4 == 0 && isPoint(lines[i]->x2, lines[i]->y2, lines[j]->x1,
                           lines[j]->y1, lines[j]->x2, lines[j]->y2))
    return true;
  return false;
}

int getRoot(int x, vector<int> &parent) {
  if (parent[x] == x)
    return x;
  return parent[x] = getRoot(parent[x], parent);
}

void merge(int u, int v, vector<int> &parent, vector<int> &componentSize) {
  int uRoot = getRoot(u, parent);
  int vRoot = getRoot(v, parent);

  if (uRoot == vRoot)
    return;

  if (uRoot < vRoot) {
    parent[vRoot] = uRoot;
    componentSize[uRoot] += componentSize[vRoot];
  } else {
    parent[uRoot] = vRoot;
    componentSize[vRoot] += componentSize[uRoot];
  }
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;

  vector<Line *> lines(n);
  vector<int> parent(n);
  vector<int> componentSize(n, 1);
  for (int i = 0; i < n; ++i) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    lines[i] = new Line(x1, y1, x2, y2);
    parent[i] = i;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (isIntersect(i, j, lines)) {
        merge(i, j, parent, componentSize);
      }
    }
  }

  int count = 0;
  int maxSize = 0;
  for (int i = 0; i < n; ++i) {
    if (parent[i] == i) {
      count++;
      maxSize = max(maxSize, componentSize[i]);
    }
  }

  cout << count << "\n" << maxSize << "\n";

  return 0;
}