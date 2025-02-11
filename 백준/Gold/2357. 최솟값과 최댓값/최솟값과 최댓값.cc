#include <bits/stdc++.h>
#define pii pair<int, int>
#define LIMIT 100001

using namespace std;

int n, m;
int arr[LIMIT], minSeg[4 * LIMIT], maxSeg[4 * LIMIT];

void build(int index, int l, int r) {
  if (l == r) {
    minSeg[index] = arr[l];
    maxSeg[index] = arr[l];
    return;
  }

  int mid = (l + r) / 2;
  build(index * 2, l, mid);
  build(index * 2 + 1, mid + 1, r);
  minSeg[index] = min(minSeg[index * 2], minSeg[index * 2 + 1]);
  maxSeg[index] = max(maxSeg[index * 2], maxSeg[index * 2 + 1]);
}

pii query(int index, int ql, int qr, int l, int r) {
  if (ql > r || qr < l) {
    return {INT_MAX, INT_MIN};
  }

  if (ql <= l && r <= qr) {
    return {minSeg[index], maxSeg[index]};
  }

  int mid = (l + r) / 2;
  auto lq = query(index * 2, ql, qr, l, mid);
  auto rq = query(index * 2 + 1, ql, qr, mid + 1, r);

  return {min(lq.first, rq.first), max(lq.second, rq.second)};
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }

  build(1, 1, n);

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    pii res = query(1, a, b, 1, n);

    cout << res.first << " " << res.second << "\n";
  }

  return 0;
}