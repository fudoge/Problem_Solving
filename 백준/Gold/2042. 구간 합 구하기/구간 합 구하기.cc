#include <bits/stdc++.h>
#define LIMIT 1000001
#define ll long long
using namespace std;

int n, m, k;

ll a[LIMIT], seg[4 * LIMIT];

void build(int index, int left, int right) {
  if (left == right) {
    seg[index] = a[left];
    return;
  }

  int mid = (left + right) / 2;
  build(index * 2, left, mid);
  build(index * 2 + 1, mid + 1, right);

  seg[index] = seg[index * 2] + seg[index * 2 + 1];
}

void update(int b, ll value, int index, int left, int right) {
  if (left == right) {
    seg[index] = value;
    return;
  }
  int mid = (left + right) / 2;
  if (b <= mid) {
    update(b, value, index * 2, left, mid);
  } else {
    update(b, value, index * 2 + 1, mid + 1, right);
  }
  seg[index] = seg[index * 2] + seg[index * 2 + 1];
}

ll subarrSum(int index, int qleft, int qright, int left, int right) {
  if (right < qleft || left > qright) {
    return 0;
  }
  if (left >= qleft && right <= qright) {
    return seg[index];
  }
  int mid = (left + right) / 2;
  ll resLeft = subarrSum(index * 2, qleft, qright, left, mid);
  ll resRight = subarrSum(index * 2 + 1, qleft, qright, mid + 1, right);

  return resLeft + resRight;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  build(1, 1, n);

  for (int i = 0; i < m + k; ++i) {
    int x, y;
    ll z;
    cin >> x >> y >> z;
    if (x == 1) {
      update(y, z, 1, 1, n);
    } else {
      cout << subarrSum(1, y, z, 1, n) << "\n";
    }
  }

  return 0;
}